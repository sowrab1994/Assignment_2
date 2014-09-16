Name: B M Sowrab
USN : 1PI12IS024

Question No-1
Consider a sales based application. The main purpose of the program is to take as an input a .csv filename that is passed in the command line argument. This file will comprise of the following details: 
Name of the item sold, Cost Price of the item, Selling Price of the Item 
Eg: 
Item, CostPrice, SellingPrice 
Keyboard, 3450, 4000 
Mouse, 500, 600 
… 
 
The .csv file will comprise of the details of the sales of the enterprise for one day. Using the details from the .csv file, compute the net profit/loss of the enterprise for one day.  

File(s) Submitted:asn2_1.c which contains the source code of the program and a csv file called Sales.csv which consists of sales of enterprise 

Program execution:

As the program is in C language, it has to be executed by one of the C compiler. After compilation if you should run the program in the format
./a.out -f Sales.csv
It will access the details of the cost price and Selling price in the file and calculate profit/loss accordingly. 

The following are the assumptions that I have made while writing the program.
1) Cost Price and Selling Price are Positive Integers.
2) The range of cost price and selling price are in the range of Integer datatype.

I have handled many error that could happen, like
1) Characters in the Cost Price and Selling Price Field.
2) Improper format of passing argument
3) Incorrect File name

Bugs in the program(that could crash my program)
1)If selling price/Cost Price is greater than 8 digit number, it will show wrong result
2)If the length of heading in the csv file is too long, it will create problem 

Note: I couldn't create Log file for the program. I was getting some error in that for which I had no time and patience.
I request you to be lenient on that fact as I had no assignment patners for help.
I think you remember the reason.