class Counter{
    public:
    void addRef();
    int delRef();
    int getRef();
    void setRef(int count);
    Counter();
    private:
    int _count;

};
Counter::Counter(){
    _count=0;
}
void Counter::addRef(){
    _count++;
}
int Counter::getRef(){
    return _count;
}
int Counter::delRef(){
    return --_count;
}