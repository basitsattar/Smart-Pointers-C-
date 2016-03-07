class COWRL{
    
    private:
    StringBuffer* sb;
    COWRL *next;
    COWRL *previous;
    Counter* ref;
    
    public:

    COWRL(char* string, int n)
    {
        sb = new StringBuffer(string,n);
        ref = new Counter();
        ref->addRef();
    }
    COWRL(StringBuffer stringb){
        sb = new StringBuffer(stringb);
        ref = new Counter();
        ref->addRef();
    }
    ~COWRL(){
        if(ref->delRef() ==0 ){
            //delete sb;
        }
    }
    COWRL(COWRL& pointer){

        sb = pointer.sb;
        ref = pointer.ref;
        ref->addRef();
    }
    
    StringBuffer& operator* (){
        return *sb;
    }
    
    StringBuffer* operator->(){
        return sb;
    }
    void append(char c)
    {
        sb = new StringBuffer(sb->strbuf(),sb->length());
        ref->delRef();
        ref = new Counter();
        ref->addRef();
        sb->append(c);
    }
    
    COWRL& operator = (COWRL& cow)
    {
        if (this != &cow) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            // Copy the data and reference pointer
            // and increment the reference count
            previous = &cow;
            cow.next= this;
            sb = cow.sb;
            ref = cow.ref;
            ref->addRef();
        }
        return *this;
    }
};
