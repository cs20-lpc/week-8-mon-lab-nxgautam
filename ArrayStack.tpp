template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO


    maxSize = i;
    this->length = 0;
    buffer = new T[maxSize];




}


template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO


    this->length = 0;

   /*while(!this->isEmpty())
    {
        this->pop();
    }
        */
}


template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO

  maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for(int i = 0; i < this->length; i++)
    {
        buffer[i] = copyObj.buffer[i];
    }


}


template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}


template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}


template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}


template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}


template <typename T>
T ArrayStack<T>::peek() const {
    // TODO


    if(this->isEmpty())
    {
        throw runtime_error("Stack is empty!");
    }


    return buffer[this->length - 1];
   
}


template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if(!this->isEmpty())
    {
        this->length--;
    }


}


template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO


    if(this->isFull())
    {
        return;
    }


    buffer[this->length++] = elem;
   




}


template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO


    if(this->length == 1)
    {return;}


    if(dir)
    {
        T topElem = buffer[this->length-1];
        for(int i = this->length - 1; i > 0; i--)
        {
            buffer[i] = buffer[i-1];
        }
        buffer[0] = topElem;
    }
    else{
        T bottomElem = buffer[0];
        for(int i = 0; i < this->length -1; i++)
        {
            buffer[i] = buffer[i+1];
        }
        buffer[this->length - 1] = bottomElem;
    }


}


template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }


    return outStream;
}


