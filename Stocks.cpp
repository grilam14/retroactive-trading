#include "Stocks.h"
#include <iostream>

using namespace std;
//This data structure is pretty terrible. There is also no dynamic nature. Need to stream in data on a server somehow. Would be nice. 

Stocks::Stocks(string d, double o, double h, double l, double c, int v, double ac)
{
  string date=d;
  double open=o;
  double high=h;
  double low=l;
  int volume=v;
  double adjustedclose=ac;//Date, Open, High, Low, Close, Volume, Adjusted Close
  double avg = high/low;
  //consider keeping avarege to reduce computation time.:x

}


Stocks::Stocks()
{
    //dtor
}
void Stocks::addDay(ticker data){
    annual[index].date=data.date;
    annual[index].open=data.open;
    annual[index].high=data.high;
    annual[index].low=data.low;
    annual[index].close=data.close;
    annual[index].volume=data.volume;
    annual[index].adjustedclose=data.adjustedclose;

    index--;//most recent data is inserted at bottom (Chronologically)
}
void Stocks::maxprofit(){
    int index=0;
    int x=1;
    while(index<254){
    if(annual[index].open<annual[index].close){
        shares=money/annual[index].open;
        money+=shares*(annual[index].close-annual[index].open);
        while(x<254){//when you decide to sell
        if(annual[index].close>annual[index+x].open){
            index=x;
            x=254;
            }
        else{x++;}
        }
        index++;
        }
        else{index++;}

    }
cout<<"Portfolio value using the optimal trading strategy after 1 year: $"<<money<<endl;
}
void Stocks::maxloss(){
    int index=0;
    int x=1;
    while(index<254){
    if(annual[index].open>annual[index].close){
        shares=money/annual[index].open;
        money+=shares*(annual[index].close-annual[index].open);
        while(x<254){//when you decide to sell
        if(annual[index].close>annual[index+x].open){
            index=x;
            x=254;
            }
        else{x++;}
            }
        index++;
        }
        else{index++;}
    }
cout<<"Portfolio value using the worst trading strategy after 1 year: $"<<money<<endl;
}
void Stocks::oneyear(){
    money=1000;
    shares=money/annual[0].open;
    money+=(shares*annual[0].open-shares*annual[254].close);
    //Color(12,"\N Hey! I'm in color!")

    cout<<"portfolio value after 1 year: $"<<money<<endl;
}

void Stocks::sixmonths(){
    money=1000;
    shares=money/annual[0].open;
    money+=(shares*annual[0].open-shares*annual[127].close);
    //Color(12,"\N Hey! I'm in color!")

    cout<<"portfolio value after 6 months: $"<<money<<endl;
}
 double dividends::addDiv(double annualdiv){
    money=1000;
    money=money+annualdiv;
    return money;
}
void dividends::oneyear(){
    money=1000;
    money+=(shares*annual[0].open-shares*annual[254].close);

    shares=money/annual[0].open;
    cout<<"Apple portfolio amount including dividends: $"<<money+annualdiv<<endl;

}
void printaccountinfo(accountinfo info){
    cout<<"name: "<<info.name<<endl;
    cout<<"password: "<<info.password<<endl;

}
void Stocks::threemonths(){
    money=1000;
    shares=money/annual[0].open;
    money+=(shares*annual[0].open-shares*annual[64].close);
    //Color(12,"\N Hey! I'm in color!")

    cout<<"portfolio value after 3 months: $"<<money<<endl;
}
void Stocks::ninemonths(){
    money=1000;
    shares=money/annual[0].open;
    money+=(shares*annual[0].open-shares*annual[191].close);
    //Color(12,"\N Hey! I'm in color!")

    cout<<"portfolio value after 9 months: $"<<money<<endl;
}
void Stocks::maxpercentagereturn(){
    int index=0;
    int x=1;
    while(index<254){
    if(annual[index].open<annual[index].close){
        shares=money/annual[index].open;
        money+=shares*(annual[index].close-annual[index].open);
        while(x<254){//when you decide to sell
        if(annual[index].close>annual[index+x].open){
            index=x;
            x=254;
            }
        else{x++;}
        }
        index++;
        }
        else{index++;}

    }
cout<<"Optimal strategy percentage return: "<<money/1000*100<<"%"<<endl;
}





