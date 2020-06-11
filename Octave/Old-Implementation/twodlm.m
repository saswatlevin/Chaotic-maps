total = 100000;
r = 1.18;

x_bar = zeros(total,1);
y_bar = zeros(total,1);

x = zeros(total,1);
y = zeros(total,1);

x(1) = 0.2;
y(1) = 0.3;



for i = 1:total - 1
  x(i + 1) = r * ((3 * y(i)) + 1) * x(i) * (1 - x(i));
  y(i + 1) = r * ((3 * x(i + 1)) + 1) * y(i) * (1 - y(i));
endfor


plot(x,y,'MarkerSize',4);
printf("\nIn twodlm\n");
x(total - 2)
x(total - 3)
x(total - 4)
x(total - 5)
