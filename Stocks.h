#ifndef STOCKS_H
#define STOCKS_H
#include <string>
using namespace std;

//Date, Open, High, Low, Close, Volume, Adjusted Close
struct ticker{
    std::string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
    double adjustedclose;
};
 struct accountinfo{
    std::string name;
    std::string password;
    };

class Stocks//base class
{
    public:
        Stocks();//Constructor1 method7
        Stocks(std::string, double, double, double, double, int, double);
        void addDay(ticker);//method1
        void maxprofit();//method2
        void oneyear();//method3
        void sixmonths();//method4
        void maxloss();//method5
        void threemonths();//method13
        void ninemonths();//method14
        void maxpercentagereturn();//method15

        int index=253;
        double money=1000;
        int shares;
        ticker annual[254];

    class Account {//nested class
        public:
        Account(){}
        //method11
        void printaccountinfo(accountinfo info){}//method12
        };
        protected:
        private:

};
class dividends:public Stocks{//derived class

    public:
        dividends(){};//constructor2 method8
        double annualdiv=(.57+.57+.52+.52);

    double addDiv(double annualdiv);//method6
    void oneyear();//overloaded method method9


};

#endif // STOCKS_H
