#include<bits/stdc++.h>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <iostream>
vector<int>v;
vector<int>factors;
int status[10001];
int numfactor[10000];
//vector<int>s1,s2;
vector<int>n1,n2;
using namespace std;
struct Bigint {

    // representations and structures

    string a; // to store the digits

    int sign; // sign = -1 for negative numbers, sign = 1 otherwise

    // constructors

    Bigint() {} // default constructor

    Bigint( string b ) { (*this) = b; } // constructor for string

    // some helpful methods

    int size() { // returns number of digits

        return a.size();

    }

    Bigint inverseSign() { // changes the sign

        sign *= -1;

        return (*this);

    }

    Bigint normalize( int newSign ) { // removes leading 0, fixes sign

        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )

            a.erase(a.begin() + i);

        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;

        return (*this);

    }

    // assignment operator

    void operator = ( string b ) { // assigns a string to Bigint

        a = b[0] == '-' ? b.substr(1) : b;

        reverse( a.begin(), a.end() );

        this->normalize( b[0] == '-' ? -1 : 1 );

    }

    // conditional operators

    bool operator < ( const Bigint &b ) const { // less than operator

        if( sign != b.sign ) return sign < b.sign;

        if( a.size() != b.a.size() )

            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )

            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];

        return false;

    }

    bool operator == ( const Bigint &b ) const { // operator for equality

        return a == b.a && sign == b.sign;

    }

    // mathematical operators

    Bigint operator + ( Bigint b ) { // addition operator overloading

        if( sign != b.sign ) return (*this) - b.inverseSign();

        Bigint c;

        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {

            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);

            c.a += (carry % 10 + 48);

            carry /= 10;

        }

        return c.normalize(sign);

    }

    Bigint operator - ( Bigint b ) { // subtraction operator overloading

        if( sign != b.sign ) return (*this) + b.inverseSign();

        int s = sign; sign = b.sign = 1;

        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);

        Bigint c;

        for( int i = 0, borrow = 0; i < a.size(); i++ ) {

            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);

            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;

            borrow = borrow >= 0 ? 0 : 1;

        }

        return c.normalize(s);

    }

    Bigint operator * ( Bigint b ) { // multiplication operator overloading

        Bigint c("0");

        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {

            while(k--) c = c + b; // ith digit is k, so, we add k times

            b.a.insert(b.a.begin(), '0'); // multiplied by 10

        }

        return c.normalize(sign * b.sign);

    }

    Bigint operator / ( Bigint b ) { // division operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c("0"), d;

        for( int j = 0; j < a.size(); j++ ) d.a += "0";

        int dSign = sign * b.sign; b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b, d.a[i]++;

        }

        return d.normalize(dSign);

    }

    Bigint operator % ( Bigint b ) { // modulo operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        Bigint c("0");

        b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b;

        }

        return c.normalize(sign);

    }

    // output method

    void print() {
        a.clear();
        a=c;
        c.clear();
    }
void prime(int n)
{
    int i, j, sqrtn;
    for( i = 2; i <= n; i++ ) status[i] = 0;
    sqrtn = int( sqrt((double) n));
    for( i = 3; i <= sqrtn; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= n; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(1);
    v.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if( status[i] == 0 )
            v.push_back(i);
    }
}

void primefactorize(int n)
{
    if(n==1)
    {
        if(numfactor[n]==0)
        {
            factors.push_back(1);
            numfactor[n]=1;
        }
    }
    else if(n>1)
    {
        int sqrtn=int(sqrt((double)n));
        int i;
        for(i=1; v[i]<=sqrtn; i++)
        {
            int count=0;
            if(n%v[i]==0)
            {
                while(n%v[i]==0)
                {
                    n/=v[i];
                    count++;
                }
                if(numfactor[v[i]]==0)
                {
                    factors.push_back(v[i]);
                }
                if(count>numfactor[v[i]])
                {
                    numfactor[v[i]]=count;
                }
            }
        }
        if( n > 1 )
        {
            if(numfactor[n]==0)
            {
                factors.push_back(n);
                numfactor[n]=1;
            }
        }
    }
}
};

int main() {
    Bigint a, b, c; // declared some Bigint variables
    string input; // string to take input

    prime(10000);
    int tc,cas=1;
    scanf("%d",&tc);
    while(cas<=tc)
    {
        int n;
        scanf("%d",&n);
        while(n>0)
        {
            int desec;
            scanf("%d",&desec);
            primefactorize(desec);
            n--;
        }
        int value=1;
        for(int z=1; z<=numfactor[factors[0]]; z++)
        {
            value=value*factors[0];
        }
        numfactor[factors[0]]=0;
        int h=value,m=value,dg;
        while(h>0)
        {
            h=h/10;
            dg=m-(h*10);
            n1.push_back(dg);
            m=h;
        }
        for(int w=n1.size()-1; w>=0; w--)
        {
          cin >> input[w]; // take the Big integer as string
        }
        a = input; // assign the string to Bigint a
        n1.clear();
        int t;
        for(t=1; t<factors.size(); t++)
        {
            int value2=1;
            for(int z2=1; z2<=numfactor[factors[t]]; z2++)
            {
                value2=value2*factors[t];
            }
            int h2=value2,m2=value2,dg2;
            while(h2>0)
            {
                h2=h2/10;
                dg2=m2-(h2*10);
                n2.push_back(dg2);
                m2=h2;
            }
            for(int w=n2.size()-1; w>=0; w--)
            {
                cin >> input[w]; // take the Big integer as string
            }
            b = input; // assign the string to Bigint b
            n2.clear();
            c = a * b; // multiplying a and b
            c.print(); // printing the Bigint
            b.clear();
            numfactor[factors[t]]=0;
        }
        factors.clear();
        printf("Case %d: ",cas);
        for(int e=0; e<a.size(); e++)
        {
            printf("%d",a[e]);
        }
        printf("\n");
        a.clear();
        cas++;
    }
    return 0;
}
