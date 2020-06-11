total = 100000;
r = 1.19

count_anomalies = 0;
count_unequal = 0;

x = zeros(total,1);
y = zeros(total,1);
c = zeros(total,1);
d = zeros(total,1); 

x(1) = 0.1;
y(1) = 0.9;

a = x(1);
b = y(1); 

% old implementation 
for i = 1:total - 1
  x(i + 1) = r * ((3 * y(i)) + 1) * x(i) * (1 - x(i));
  y(i + 1) = r * ((3 * x(i + 1)) + 1) * y(i) * (1 - y(i));
endfor



for i = 1:total - 1
  if (x(i) > 1 || x(i) < 0)
    count_anomalies = count_anomalies + 1;
  else
    printf("");
  endif
endfor


% new implementation 
for i = 1:total - 1
  a = r * ((3 * b) + 1) * a * (1 - a);
  b = r * ((3 * a) + 1) * b * (1 - b);
  c(i + 1) = a;
  d(i + 1) = b;
  
endfor



for i = 1:total - 1
  if (x(i) != c(i))
    count_unequal = count_unequal + 1;
  endif
endfor

  
%printf("\ncount_unequal = \n");
count_unequal

%printf("\ncount_anomalies = \n");
count_anomalies

%figure() is used to display multiple plot windows

figure(1);
plot(x,y,'MarkerSize',4);
figure(2);
plot(c,d,'MarkerSize',4);

printf("\nIn twodlm\n");
%x(total - 2)
%x(total - 3)
%x(total - 4)
%x(total - 5)
