function henon()
	iterator =10
	x=zeros(iterator,1);
	y=zeros(iterator,1);
	count_x=0
	count_y=0
	x(1)=0;
	y(1)=0;
	a=1.4;
	b=0.3;
	for i = 1:(length(x)-1)
		x(i+1)=1-(a.*x(i)*x(i))+y(i);
		y(i+1)=(b.*x(i));
		
		%%if x(i+1) >= 1.0 || x(i+1) <= -1.0 
		%%count_x=count_x+1;
		%%elseif y(i+1) > = 1.0 || y(i+1) <=-1.0
		%%count_y=count_y+1;
		%%else
		%%print("None")
		%%end
	endfor
	x
endfunction

henon()
