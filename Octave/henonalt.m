%% The Henon Map
% Created by Moysis Lazaros.
%
% This is a simple implementation of the Henon
% system. It is a discrete time system that maps a point $(x_n,y_n)$ in the
% following fashion:
%
% $x_{n+1}=1-a x_n^2 + y_n$
%
% $y_{n+1}=b x_n$
%
% where a and b are the system parameters
%% The code
% We start by defining the initial values
x(1)=0;
y(1)=0;
a=1.4;
b=0.3;
count_x=0;
count_y=0;
% and now we begin the iteration (10000 iterations):
for i=2:1000
	x(i)=1-1.4*(x(i-1)^2)+y(i-1);
	y(i)=b*x(i-1);
endfor
plot(x,y,'.','MarkerSize',4)
title('Henon Map')

for i=1:length(x)
	if x(i) < -1 || x(i) > 1
		count_x=count_x+1;
	endif
	
	if y(i) < -1 || y(i) > 1
		count_y=count_y+1;
	endif
endfor

count_x
count_y
%printf("\n\n")
x
%printf("\n\n")
%y
%% References
% [1] M. Henon (1976). "A two-dimensional mapping with a strange
% attractor". Communications in Mathematical Physics 50 (1): 69�77