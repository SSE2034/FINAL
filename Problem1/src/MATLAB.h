class Matrix{
    public:
        //implement your class member function definition as written in paper.
        void set_value(int row, int col, int val);
        void print_matrix();
    private:
        int* value;
        int rownum;
        int colnum;
};

//implement your class member functions as written in paper.

void Matrix::print_matrix(){
    for(int i=0;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            std::cout << /*fill your code*/ << " ";
        }
        std::cout << std::endl;
    }
}
