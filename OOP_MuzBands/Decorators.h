#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED


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
#endif // DEC_H_INCLUDED
