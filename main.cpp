/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) { } //1
    int value; //2
    std::string name; //3
};

struct CompareValues                              //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b !=nullptr)
        {
            if (a->value < b->value) return a;
            if (a->value > b->value) return b;
        }
        return nullptr;
    }
};

struct U
{
    float name1 { 0 }, name2 { 0 };
    float memberFunctionU(float* updatedValue)      //12
    {
        if(updatedValue != nullptr)
        {
            std::cout << "U's name1 value: " << this->name1 << std::endl;
            this->name1 = *updatedValue;
            std::cout << "U's name1 updated value: " << this->name1 << std::endl;
            while( std::abs(this->name2 - this->name1) > 0.001f ) 
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
                this->name2 += .2f;
            }
            std::cout << "U's name2 updated value: " << this->name2 << std::endl;
            return this->name2 * this->name1;
        }
        std::cout <<"Function contains null pointers!" << std::endl;
        return 0;
    }
};

struct S
{
    static float staticFunctionS(U* that, float* updatedValue )//10
    {
        if (that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's name1 value: " << that->name1 << std::endl;
            that->name1 = *updatedValue;
            std::cout << "U's name1 updated value: " << that->name1 << std::endl;
            while( std::abs(that->name2 - that->name1) > 0.001f )
            {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
                that->name2 += .2f;
            }
            std::cout << "U's name2 updated value: " << that->name2 << std::endl;
            return that->name2 * that->name1;
        }
        std::cout <<"Function contains null pointers!" << std::endl;
        return 0;
    }
}; 
    
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(45, "c");                                             //6
    T t2(25, "m");                                             //6
    
    CompareValues f;                                            //7
    auto* smaller = f.compare(&t1, &t2); //8
    if (smaller != nullptr)
    {
         std::cout << "the smaller one is << " << smaller->name << std::endl; //9       
    }
    else
    {
        std::cout << "One of the following errors happened: 1) One or both instances contain null pointers or 2) Both instances' member variables are equal." << std::endl;
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << S::staticFunctionS(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.memberFunctionU( &updatedValue ) << std::endl;
}
