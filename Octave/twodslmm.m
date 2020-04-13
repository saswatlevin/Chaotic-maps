M_PI  = 3.14592;  
total = 100000;
x = zeros(total,1);
y = zeros(total,1);

x(1) = 0.1;
y(1) = 0.1;

alpha1 = 0.915
beta1  = 2.97


for i = 1:total - 1
	x(i + 1) = alpha1 * (sin(M_PI * y(i)) + beta1) * x(i) * (1 - x(i));
	y(i + 1) = alpha1 * (sin(M_PI * x(i + 1)) + beta1) * y(i) * (1 - y(i));
endfor

plot(x,y,'.','MarkerSize',4);
printf("\nIn twodslmm\n");
x(total - 2)
x(total - 3)
x(total - 4)
x(total - 5)
