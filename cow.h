class COW{
    
    private:
    StringBuffer* sb;
    Counter* ref;
    
    public:

    COW(char* string, int n)
    {
        sb = new StringBuffer(string,n);
        ref = new Counter();
        ref->addRef();
    }
    COW(StringBuffer stringb){
        sb = new StringBuffer(stringb);
        ref = new Counter();
        ref->addRef();
    }
    ~COW(){
        if(ref->delRef() ==0 ){
            //delete sb;
        }
    }
    COW(COW& pointer){

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
    
    COW& operator = (COW& cow)
    {
        if (this != &cow) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            // Copy the data and reference pointer
            // and increment the reference count
            sb = cow.sb;
            ref = cow.ref;
            ref->addRef();
        }
        return *this;
    }
};
