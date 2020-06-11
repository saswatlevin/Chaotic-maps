total = 10000;
myu = 0.9;

x_bar = zeros(total,1);
y_bar = zeros(total,1);

x = zeros(total,1);
y = zeros(total,1);

x(1) = 0.1;
y(1) = 0.1;



for i = 1:total - 1
  x_bar(i + 1) = myu * (y(i) * 3) * x(i) * (1 - x(i));
  x(i + 1) = 4 * x_bar(i + 1) * (1 - x_bar(i + 1));
  y_bar(i + 1) = myu * (x(i + 1) + 3) * y(i) * (1 - y(i));
  y(i + 1) = 4 * y_bar(i + 1) * (1 - y_bar(i + 1)); 
endfor

plot(x,y,'.','MarkerSize',4);

%{

%}

