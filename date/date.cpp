// date.cpp
// Implementation of the Date class

#include "date.h"


Date::Date(const int day, const Month month, const int year):
_day{day},_month{month},_year{year}
{
	if(!((_day > 0) && (_day <= daysInMonth())) || _year < 0){
		throw DateException();
	}
}
Date Date::_default{1, Month::January, 1900};
Date::Date(){	
	Date::setDefaultDate(1, Month::January, 1900);
	_day = Date::_default.day();
	_month = Date::_default.month();
	_year = Date::_default.year();
}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

//Exercise 2.3
bool Date::operator==(const Date& rhs) const{
	
	if(rhs.day() == _day){
		if(static_cast<int>(rhs.month()) == static_cast<int>(_month)){
			if(rhs.year() == _year){
				return true;
			}
		}
	}
	return false;
}

//Exercise 2.4
void Date::addDay(){
	//convert current Date to total num of days
	auto numOfDays = static_cast<double>(_year)*365.25 + ((static_cast<double>(_month) - 1)*365.25)/12 + static_cast<double>(_day);
	numOfDays = numOfDays + 1; //add one day
	auto temp = numOfDays/365.25;
	//convert numOfDays to years, months and day
	_year = static_cast<int>(temp); 
	temp = (temp - _year)*12;
	auto temp2 = static_cast<int>(temp);
	_month = static_cast<Month>(temp2 + 1);
	auto temp3 = (temp - temp2)*(365.25/12) + 0.0001;
	_day = static_cast<int>(temp3);
}
//Exercise 2.5

void Date::setDefaultDate(int day, Month month, int year){
	Date temp{day,month,year};
	Date::_default = temp;
}
