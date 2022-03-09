#include <iostream>
#include <string>
#include <cmath>

char getSymbolByNumber ( int number, char numSymb ) // from end
{
    //std::cout << number  << "\n";
    char symbol;
    int degree = std::pow ( 10, ++numSymb ); // ! ++
    symbol = ( number % degree ) / ( degree / 10 );
    return symbol;
}

std::string repeatSymbol ( char symbol, int number )
{
    //std::cout << number;
    std::string str = "";
    for ( ; number > 0 ; number-- )
    {
        str += symbol;
    }
    return str;
}   

std::string getRomanianNumber( int number )
{
    char romanianNumbers[8] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '!' };
    std::string romanianNumber = "";
    if ( number < 0 )
    {
        number = -number;
        romanianNumber = "-";
    }
    short degree = 0;
    std::string space = "";
    while ( std::pow( 10, degree ) <= number )
    {
        char symbol = getSymbolByNumber ( number, degree );
        degree++;
        //std::cout << "\nstart while " << degree <<  "\n";
        if ( symbol == 0 ) continue;
        //std::cout << "\nis more then 0 \n";
        if ( symbol <= 3 ) romanianNumber = repeatSymbol ( romanianNumbers[ (degree - 1) * 2 ], symbol ) + space + romanianNumber ;
        if ( ( symbol > 4 ) && ( symbol < 9 ) ) romanianNumber = romanianNumbers[ (degree - 1) * 2 + 1 ] + repeatSymbol ( romanianNumbers[ (degree - 1) * 2 ], ( symbol - 5 ) ) + romanianNumber;
        //std::cout << "\nis more then 3 \n"; 
        if ( symbol == 4 ) romanianNumber = romanianNumbers[ (degree - 1 ) * 2 ] + space + romanianNumbers[ (degree - 1 ) * 2 + 1 ] + romanianNumber;
        if ( symbol == 9 ) romanianNumber = romanianNumbers[ (degree - 1 ) * 2 ] + space + romanianNumbers[ (degree - 1 ) * 2 + 2 ] + romanianNumber;
        //std::cout << "\nend while " << degree << "\n";
    }
    return romanianNumber;
}

int main ()
{
    int number;
    std::cin >> number;
    //std::cout << "In romanian " << number << " is equal to : " << getRomanianNumber ( number ) << "\n";
    std::cout << getRomanianNumber ( number );
    return 0;
}
