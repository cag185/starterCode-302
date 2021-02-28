//use an array to create a stack implementation
//Caleb Gibson

template <typename T>
class arrayStack{
    //variables here
    private:
        //use an array
        //create pointer to type T arrayStack
        T *arrPoint;
        //size variable
        std::size_t stackLength;
        std::size_t usedSpace;
        //flag h -- if set, double array when more than half of array is used
        bool h;
    public:
        //anytime stack becomes full, double the array
        //stacks bottom entry is the beggining of array

        //constructor
        arrayStack();

        //destructor
        ~arrayStack();

        //push function
        void push(T &val);

        //pop function
        T pop(T);

        //peek function
        T peek();

        //is empty
        bool isEmpty();

        //size function
        std::size_t size();

        //return used space
        std::size_t usedSpace();

        //resize function
        void resize();

        //set flagH
        void setH(bool &choice);
};