total = 100000;
myu = 0.900;

x_bar = zeros(total,1);
y_bar = zeros(total,1);

x = zeros(total,1);
y = zeros(total,1);
c = zeros(total,1);
d = zeros(total,1);

count_anomalies = 0;
count_unequal = 0;

a_bar = x_bar(1);
b_bar = y_bar(1);

x(1) = 0.9;
y(1) = 0.1;

a = x(1);
b = y(1);

% old implementation 
for i = 1:total - 1
  x_bar(i + 1) = myu * (y(i) * 3) * x(i) * (1 - x(i));
  x(i + 1) = 4 * x_bar(i + 1) * (1 - x_bar(i + 1));
  y_bar(i + 1) = myu * (x(i + 1) + 3) * y(i) * (1 - y(i));
  y(i + 1) = 4 * y_bar(i + 1) * (1 - y_bar(i + 1)); 
endfor

% new implementation 
for i = 1:total - 1
  a_bar = myu * (b * 3) * a * (1 - a);
  a = 4 * a_bar * (1 - a_bar);
  b_bar = myu * (a + 3) * b * (1 - b);
  b = 4 * b_bar * (1 - b_bar);
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

figure(1)
plot(x,y,'.','MarkerSize',4);
figure(2)
plot(c,d,'.','MarkerSize',4);
printf("\nIn twodlalm\n")
count_anomalies
count_unequal
%{

%}

