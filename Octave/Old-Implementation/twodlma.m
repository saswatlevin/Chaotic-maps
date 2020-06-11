total = 100000;
x = zeros(total,1);
y = zeros(total,1);
myu1 = 3.04;
myu2 = 3.04;
lambda1 = 0.17;
lambda2 = 0.15;
x(1) = 0.9;
y(1) = 0.9;


for i = 1:total - 1
	x(i + 1) = x(i) * myu1 * (1 - x(i)) + lambda1 * (y(i) * y(i));
	y(i + 1) = y(i) * myu2 * (1 - y(i)) + lambda2 * ((x(i) * x(i)) + x(i) * y(i)); 
endfor
printf("\nIn twodlma\n");
plot(x,y,'.','MarkerSize',4);
x(total - 2)
x(total - 3)
x(total - 4)
x(total - 5)


