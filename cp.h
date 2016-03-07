class CP{
    
    private:
    StringBuffer* sb;
    public:

    CP(char* string, int n)
    {
        sb = new StringBuffer(string,n);
    }
    CP(StringBuffer stringb){
        sb = new StringBuffer(stringb);
    }
    ~CP(){
        //delete sb;
    }
    CP(CP& pointer){
        sb = new StringBuffer(pointer->strbuf(), pointer->length());
    }
    StringBuffer& operator* (){
        return *sb;
    }
    
    StringBuffer* operator->(){
        return sb;
    }
    CP& operator = (CP& cp)
    {
        if (this != &cp) // Avoid self assignment
        { 
            sb = new StringBuffer(cp->strbuf(), cp->length());
        }
        return *this;
    }
};