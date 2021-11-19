//This program displays the calendar of the input year in vertical format

#include<iostream>
#define f(i,a,n) for(int i=a ;i<n ;i++)
using namespace std;

/* The integer function dayofweek returns a number corresponding to the day at which 1st January of input year falls i.e. day at which 01/01/.... occurs
Day		Value of n
Monday 		1
Tuesday		2
Wednesday	3
Thursday	4
Friday		5
Saturday	6
Sunday		0 */
int dayofweek(int y)  
{  
	int d=1,m=1;
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
	
    y -= m < 3;  //If m<3, return y-1, else return y

    //Using Tomohiko Sakamoto’s Algorithm
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}

//The boolean function checkYear is used to check is the input year is leap year or not. If it is a leap year, true is returned, else false is returned.
bool checkYear(int year)  
{  

    if (year % 400 == 0)  
        return true;  
  
    if (year % 100 == 0)  
        return false;  
  
    if (year % 4 == 0)
        return true;  
        
    return false;  
}  

int main()
{
	int y;
	cout<<"Enter year : ";
	cin>>y;
	
	int n = dayofweek(y);
//	cout<<n<<endl<<endl;
	
	/* The following lines modify the value of n to give the following result
	Day		Value of n
	Monday 		1
	Tuesday		2
	Wednesday	3
	Thursday	4
	Friday		5
	Saturday	6
	Sunday		7 */
	n%=7;
	if(!n)
	n=7;
	
	int m=1,d=31,febday;
	
	//Set containing all months of the year
	string month[12]={"January", "February" ,"March" , "April" , "May" ,"June" ,"July" , "August" ,"September" ,"October" ,"November" ,"December"};
	int i=1;
	
//	If input year is leap year, number of days in Februrary are 29, else 28.
	if(checkYear(y))
	febday=29;
	else
	febday=28;
	
	//Set containing all days of the week
	string day[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
	
	while(i<=12)
	{
		//Print Current Month of the year
		cout<<month[i-1]<<" "<<y<<endl;
		int j=1;
//		cout<<"Mon \t"<<"Tue \t"<<"Wed \t"<<"Thu \t"<<"Fri \t"<<"Sat \t"<<"Sun \t"<<endl;
		
		//If Current month is February, set number of days as determined in line 74:77
		if(i==2)
		d=febday;
		
		int date=1;
		int n1=n;
		
		f(k,0,7)
		{
			//Print current day of the week
			cout<<day[k]<<" ";
			//If first week does not contain a date corresponding to the current day, print tab
			if(n>k+1)
			{
				cout<<"\t";
			}
			
			//To calculate first date falling on current day
			int tmp;
			if(n>k+1)
			tmp=8-n+k+1;
			else
			tmp=k+1-n+1;
			
			//To print all dates on current day
			while(tmp<=d)
			{
				//Adjusting soace for one digit and two digit dates
				if(tmp<10)
				cout<<tmp<<"   ";
				else
				cout<<tmp<<"  ";
				
				tmp+=7;
				
				//If last date of the month lies on cuurent day, store day number in n1
				if(tmp==d)
				n1=k+1;
			}
			cout<<endl;
			
		}
		//Start next month from day next to current day
		n=n1+1;
//		cout<<"n1 is "<<n1<<endl;
		
		//If Current month is July, set number of days for next iteration as 31 (August), else set to 30
		if(d==31 && i!=7)
		d=30;
		else
		d=31;
		
		cout<<endl<<endl;
		i++;
		
	}
	
}
