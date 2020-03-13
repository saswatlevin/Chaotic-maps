number=100;
unzero=0.0000001;
%x=zeros(number,1);
x=mod(sqrt(5),1);

for i =1:number
	plot(x,x,'.','MarkerSize',4); 
	hold on
	if x < 0.5
		x = 2 * x
	elseif x > 0.5
		x = 2 - 2 * x	
    endif
endfor	

%{
for i=2:amount-1
	y(i)=x(i+1);
endfor
%}


%plot(x,y,'.','MarkerSize',4)
%title('Tent Map')

%myu should always be 2
%