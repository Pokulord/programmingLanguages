#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED


/*

Базовые итераторы и декораторы


*/
template<class Type>
class Iterator
{
protected:
    Iterator() {}

public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type GetCurrent() const = 0;
};

template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *Decorator;

public:
    IteratorDecorator(Iterator<Type> *Iterator)
    {
        Decorator = Iterator;
    }

    virtual ~IteratorDecorator() { delete Decorator; } // Destructor
    void First() { Decorator->First(); }
    void Next() { Decorator->Next(); }
    bool IsDone() const { return Decorator->IsDone(); }
    Type GetCurrent() const { return Decorator->GetCurrent(); }

};
#endif // DEC_H_INCLUDED
