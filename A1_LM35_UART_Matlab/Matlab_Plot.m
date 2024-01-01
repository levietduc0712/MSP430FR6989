clear all;
close all;
clc;

s = serial('COM5','BaudRate',9600);

fopen(s);
i = 1;

while(1)
    val = fscanf(s);
    numval(i) = str2double(val);
    plot(numval(2:3:end),'b','LineWidth',1)
    pause(0.001);

    i = i + 1;
end
