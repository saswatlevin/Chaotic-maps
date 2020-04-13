M_PI = 3.14592;
total = 100000;
x = zeros(total,1);
y = zeros(total,1);
myu = 0.9;
x(1) = 0.9;
y(1) = 0.9;

for i = 1:total
	x(i + 1) = sin(M_PI * myu * (y(i) + 3) * x(i) * (1 - x(i)));
	y(i + 1) = sin(M_PI * myu * (x(i + 1) + 3) * y(i) * (1 - y(i)));
endfor

plot(x,y,'.','MarkerSize',4);
printf("\nIn twodlasm\n");
x(total - 2)
x(total - 3)
x(total - 4)
x(total - 5)

