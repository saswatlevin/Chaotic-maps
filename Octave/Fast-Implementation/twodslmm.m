M_PI  = 3.14592;  
total = 100000;
x = zeros(total,1);
y = zeros(total,1);

c = zeros(total,1);
d = zeros(total,1);

x(1) = 0.9;
y(1) = 0.1;
a = x(1);
b = y(1);

count_anomalies = 0;
count_unequal = 0;
alpha1 = 0.995
beta1  = 3.000

% old implementation 
for i = 1:total - 1
  x(i + 1) = alpha1 * (sin(M_PI * y(i)) + beta1) * x(i) * (1 - x(i));
  y(i + 1) = alpha1 * (sin(M_PI * x(i + 1)) + beta1) * y(i) * (1 - y(i));
endfor

% new implementation 
for i = 1:total - 1
  a = alpha1 * (sin(M_PI * b) + beta1) * a * (1 - a);
  b = alpha1 * (sin(M_PI * a) + beta1) * b * (1 - b);
  c(i + 1) = a;
  d(i + 1) = b;
endfor

for i = 1:total - 1
  if (x(i) > 1 || x(i) < 0)
    count_anomalies = count_anomalies + 1;
  else
    printf("");
  endif
endfor

for i = 1:total - 1
  if (x(i) != c(i))
    count_unequal = count_unequal + 1;
  endif
endfor

% figure() is used to allow different plot windows  
figure(1)
plot(x,y,'.','MarkerSize',4);
figure(2)
plot(c,d,'.','MarkerSize',4);

printf("\nIn twodslmm\n");
count_anomalies
count_unequal

% x(total - 2)
% x(total - 3)
% x(total - 4)
% x(total - 5)
