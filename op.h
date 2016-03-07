class OP{
    
    private:
    StringBuffer* sb;
    bool owned;
    
    public:

    OP(char* string, int n)
    {
        sb = new StringBuffer(string,n);
        owned = true;
    }
    OP(StringBuffer stringb){
        sb = new StringBuffer(stringb);
        owned = true;
    }
    ~OP(){
        if(owned){
            delete sb;
        }
    }
    OP(OP& pointer){
        sb = pointer.sb;
        pointer.owned = false;
        owned = true;
    }
    StringBuffer& operator* (){
        return *sb;
    }
    
    StringBuffer* operator->(){
        return sb;
    }
    
    OP& operator = (OP& op)
    {
        if (this != &op) // Avoid self assignment
        {
            //delete the old data
            delete sb;

            // Copy the data 
            sb = op.sb;
            op.owned = false;
            owned=true;
        }
        return *this;
    }
};