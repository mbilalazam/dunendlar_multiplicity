% Read the data from the CSV file
data = readtable('data_protons.csv');

% Extract ke and len_inLAr columns
ke = data.ke.*1000;
len_inLAr = data.len_inLAr;

% Given parameters
A = 30.573;
a = 0.555;
B = 0.133;
b = 1.289;

% Custom function with provided parameters
custom_func = @(x) A * (x.^a) + B * (x.^b);
fitted_vals = custom_func(len_inLAr);

% Fit the data using a custom power law
f = fittype('a*x^m + c*x^n', 'independent', 'x', 'coefficients', {'a', 'm', 'c', 'n'});
options = fitoptions(f);
options.Algorithm = 'Trust-Region';  % Using Trust-Region algorithm
options.StartPoint = [A, a, B, b];
options.Lower = [0.1 0.1 0.1 0.1];
options.Upper = [100 10 100 10];

[fit_result, gof, output] = fit(len_inLAr, ke, f, options);
fitted_auto_vals = fit_result(len_inLAr);

% Extract confidence intervals for the parameters
conf_intervals = confint(fit_result);
errors = (conf_intervals(2, :) - conf_intervals(1, :)) / 2;

% Plotting
figure;
scatter(len_inLAr, ke, 25, 'r', 'filled');
hold on;
plot(len_inLAr, fitted_vals, 'b', 'LineWidth', 2);
plot(len_inLAr, fitted_auto_vals, 'g', 'LineWidth', 2);

set(gca, 'XScale', 'linear');
set(gca, 'YScale', 'linear');
xlabel('Range of Protons (cm)');
ylabel('Kinetic Energy of Protons (MeV)');

fit_equation_aleena = sprintf('MicroBooNe: T = %.3f * (R^{%.3f}) + %.3f * (R^{%.3f})', A, a, B, b);
% fit_equation_bilal = sprintf('2x2 DUNE: T = %.3f ± %.3f * (R^{%.3f ± %.3f}) + %.3f ± %.3f * (R^{%.3f ± %.3f})', ...
%     fit_result.a, errors(1), fit_result.m, errors(2), fit_result.c, errors(3), fit_result.n, errors(4));
fit_equation_bilal = sprintf('2x2 DUNE: T = %.3f * (R^{%.3f}) + %.3f * (R^{%.3f})', fit_result.a, fit_result.m, fit_result.c, fit_result.n);

legend('Data', fit_equation_aleena, fit_equation_bilal);
grid on;
xlim([0 30]);
ylim([0 250]);
hold off;
saveas(gcf, 'protons_linear_with_errorBars.png');
