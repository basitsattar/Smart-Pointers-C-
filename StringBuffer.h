class StringBuffer{

    public :
        StringBuffer();  //default constructor
        ~StringBuffer();                //destructor; would delete the allocated buffer
        StringBuffer(const StringBuffer&);              //constructor for shallow copying
        StringBuffer(char*,int);   //constructor to convert a char* to StringBuffer
        char charAt(int) const;   //returns the character at the passed index
        int length() const;                            //returns the length of the buffer
        char* strbuf();                            //returns the length of the buffer
        void reserve(int n);                         //allocates memory for the string, according to the passed character length
        void append(char);                          //appends a single character at the end
    
    private:
        char* _strbuf;                                   //buffer to store the original string
        int _length;                                       //length of the string
};


StringBuffer::StringBuffer()
{
    _length = 0;
    _strbuf = new char[0];
}
StringBuffer::~StringBuffer()
{
    delete[] _strbuf;
    _length = 0;
}

StringBuffer::StringBuffer(const StringBuffer& sb)
{
    reserve(sb._length);
    _strbuf = sb._strbuf;
}

StringBuffer::StringBuffer(char* string, int n)
{
    _length = n;
    _strbuf = new char[_length];
    _strbuf = string;
    
}

int StringBuffer::length() const
{
    return _length;
}
char* StringBuffer::strbuf()
{
    return _strbuf;
}

void StringBuffer::reserve(int n)
{
    if(_length == 0 ){
        _strbuf = new char[n];
        _length = n;
    }else if(n<_length){
        return;   
    }
    else{
        
        char * temp = new char[_length];
        strncpy(temp,_strbuf,_length);
        _strbuf = new char[n];
        strncpy(_strbuf,temp,n);
        delete[] temp;
        _length = n ;
         
    }
}
void StringBuffer::append(char c)
{
    reserve(_length+1);
    *(_strbuf+(_length-1)) = c; 
}
char StringBuffer::charAt(int n) const{
    return *(_strbuf+n);
}
