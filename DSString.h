//
// Created by dalla on 9/21/2021.
//

#ifndef MACKENZIE_PA2_DSSTRING_H
#define MACKENZIE_PA2_DSSTRING_H


#include <iostream>
#include <cstring>

class DSString{

private:
    char* str = nullptr;
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/


public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    DSString();
    DSString(const char* s);
    DSString(const DSString& arg);
    ~DSString();

    /**
     * Overloaded Assignment Operators
     */
    DSString& operator= (const char* s);
    DSString& operator= (const DSString& arg);

    /**
     * Overloaded non-modifying string concat
     * @return
     */
    DSString operator+ (const DSString& arg);

    /**
     * Standard relational operators.  Feel free to add additional.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/

    bool operator== (const char* s);
    bool operator== (const DSString& arg);
    bool operator> (const DSString& arg);
    bool operator> (const char* s);        //ask if i should overload these operators as well since I can already check equality

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char& operator[] (const int num);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength();

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int start, int numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<< (std::ostream& os, const DSString& arg);
    friend std::istream& operator>> (std::istream& os, DSString& arg);
    bool search(const DSString& query);
    DSString& islower();

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.

};





#endif //MACKENZIE_PA2_DSSTRING_H
