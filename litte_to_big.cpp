/*
Name:       Rachel Vanderlerly
Due Date:   September 30 2022
Class:      Network Programming
Profesor:   Dr.Zhao
Assignment: Program 2
Description: This program converts an IP v4 address, such as 198.17.223.4 
into network byte order in binary format, and then convert the binary value 
into an equivalent decimal value, and then print the IP v4 address, 
binary stream, and decimal value.  
*/ 
#include <arpa/inet.h>
#include <iostream>
#include <string>
#define MAXSIZE 16

using std::cout;
using std::cin;
using std::string;

int main()
    {
    char IPV4_address[MAXSIZE];     //A string holding the users input IPV4 address
    char* IPV4_2D[4];               //To hold the ipv4 numbers without the . in them
    char* binary_big_endian;                //To hold the binary 
    unsigned int decimal_num;
    struct sockaddr_in mine;
    std::string answer = "Y";


while (answer == "Y" || answer =="y")
    {
    //Get the IPV4 Address
    cout<<"Enter an IP4 Address:";
    fgets(IPV4_address,MAXSIZE,stdin);
    printf("Your IPV4 address is %s",IPV4_address);

    printf("The string length is %lu",strlen(IPV4_address));

    //Convert your IP Address to binary
    cout<<inet_pton(AF_INET,IPV4_address,&(mine.sin_addr));
    cout<<"Your IPV4 address in binary is"<<mine.sin_addr.s_addr<<"\n";
    decimal_num = mine.sin_addr.s_addr;
    cout<<"Your IPV4 address in binary is"<<decimal_num<<"\n";

    //Convert the number in s_addr to binary. 
    //Right now its the decimal equivelent inside mine.sin_addr.s_addr
    int counter = 0;
    unsigned int temp_dec = decimal_num;
    cout<<"The temp_dec is: "<<temp_dec<<"\n";
while (counter < 32)
    {
        int remainder;
        remainder = temp_dec % 2;
        if (remainder == 1){
            binary_big_endian[counter]= '1';
        }
        else{
            binary_big_endian[counter] = '0';
        }
        counter++;
        temp_dec = temp_dec / 2;
    }
    printf("The big endian of the binary number is %s \n",binary_big_endian);
    cout<<"Do you want to run again?";
    cin>>answer;
    cin.ignore();
    }
return 0;
}