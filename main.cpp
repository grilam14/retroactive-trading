#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include "Stocks.h"


using namespace std;

double addDouble(string word){//function 1
    string temp;
    temp=word;
    double x;
    x=atof(temp.c_str());
    return x;
}
int addInt (string word){//function 2
    string temp;
    temp=word;
    int x;
    x=atoi(temp.c_str());
    return x;
}
void stockinfo(int a){//function 3
    if(a==0){
    cout<<"Netflix Inc. is an American multinational entertainment company founded on August 29, 1997 in Scotts Valley, California, by Reed Hastings and Marc Randolph. It specializes in and provides streaming media and video on demand online and DVD by mail"<<endl;
    }
    if(a==1){
    cout<<"Chipotle Mexican Grill, Inc. is an American chain of fast food restaurants in the United States, United Kingdom, Canada, Germany, and France, specializing in tacos and burritos."<<endl;
    }
    if(a==2){
    cout<<"Amazon.com, Inc., often referred to as simply Amazon, is an American electronic commerce and cloud computing company with headquarters in Seattle, Washington."<<endl;
    }
    if(a==3){
    cout<<"Apple Inc. is an American multinational technology company headquartered in Cupertino, California, that designs, develops, and sells consumer electronics, computer software, and online services."<<endl;
    }
}

int passwordcheck(string password){//function 4

    if(password.length()<3){
        return 0;
    }
    else{return 1;}
}

int main(){
    ticker info;
    int correctpassword=0;
    cout<<"Create account username: "<<endl;
        string name;
        cin>>name;
    while(correctpassword==0){
    cout<<"Create password: (password must be greater than 2 characters for security)"<<endl;
        string pass;
        cin>>pass;
    correctpassword=passwordcheck(pass);
    }
    string password;
    accountinfo personal;
    personal.name=name;
    personal.password=password;

    ifstream data;
    int counter=0;
    int stockcounter=0;

    dividends div;

    while(counter==0){
    int correct=0;
    while(correct==0){
    cout<<"Portfolio Options: Netflix, Chipotle, Amazon, Apple (Choose one) "<<endl;
    string symbol;
    cin>>symbol;
//file.open("C:\\Demo.txt", ios::in);
    if(symbol=="Netflix"){
    data.open("/home/user/Documents/Project1_Grillot/Netflix.csv");
    if(data.fail()){
    cout<<"Something happened"<<endl;}
    correct++;
    stockcounter=0;
    }
    if(symbol=="Chipotle"){
    data.open("/home/user/Documents/Project1_Grillot/Chipotle.csv");
    if(data.fail()){
    cout<<"Something happened"<<endl;}
    correct++;
    stockcounter=1;
    }
    if(symbol=="Amazon"){
    data.open("/home/user/Documents/Project1_Grillot/Amazon.csv");
    if(data.fail()){
    cout<<"Something happened"<<endl;}
    correct++;
    stockcounter=2;
    }
    if(symbol=="Apple"){
    data.open("/home/user/Documents/Project1_Grillot/Apple.csv");
    if(data.fail()){
    cout<<"Something happened"<<endl;}
    dividends div;
    correct++;
    stockcounter=3;
    }
    }

    string word;
    Stocks annualdata;//class//struct
    int lineindex=0;
    while(getline(data, word, '\n')){

            stringstream ss;
            int wordindex=0;
            if(lineindex>0){
            ss<<word;

            while(getline(ss,word,',')){
                if(wordindex==0){
                    info.date=word;
                    }
                 if(wordindex==1){
                    info.open=addDouble(word);
                    }
                 if(wordindex==2){
                    info.high=addDouble(word);
                    }
                 if(wordindex==3){
                    info.low=addDouble(word);
                    }
                 if(wordindex==4){
                    info.close=addDouble(word);
                    }
                 if(wordindex==5){
                    info.volume=addInt(word);
                    }
                 if(wordindex==6){
                    info.adjustedclose=addDouble(word);
                    }
            wordindex++;
                }
            }
        annualdata.addDay(info);
        lineindex++;
    }
    stockinfo(stockcounter);
    annualdata.maxprofit();
    annualdata.threemonths();
    annualdata.sixmonths();
    annualdata.ninemonths();
    annualdata.oneyear();
    annualdata.maxloss();
    annualdata.maxpercentagereturn();
    double money;
    double divs=div.annualdiv;
    if(stockcounter==3){//dividends only apply to Apple because they are the only ones who have it
        money=div.addDiv(divs);
        div.oneyear();
        }
    Stocks::Account printpersonal;//creates instance of Account nested class
    printpersonal.printaccountinfo(personal);//I do not know why this does not print.


  cout<<"press q to end program, or anything else to continue."<<endl;
  string quit;
  cin>>quit;
  if(quit=="q"){
    counter++;
    break;

  }

}

}
