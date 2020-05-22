#pragma once
#include <iostream>

template <class T>
class Vector
{
public:
    Vector(int sz = 0) : lenght(sz)
    {
        data = new T[sz];
        for(int i = 0;i<sz;++i) 
            data[i]=0;
    }

    Vector(Vector &other):Vector(other.lenght)
    {
        for(int i = 0;i<lenght;++i)
            data[i]=other.data[i];
    }

    Vector &operator=(Vector const &other)
    {
        if (&other == this)
            return *this;

        delete[] data;
        data = new T[other.lenght];
        lenght = other.lenght;
        for (int i = 0; i < lenght; ++i)
            data[i] = other.data[i];
        return *this;
    }

    Vector operator+(Vector const &other)
    {
        Vector res(lenght);
        for(int i = 0;i<lenght;++i)
            res.data[i]=data[i]+other.data[i];
        return res;
    }

    Vector operator-(Vector const &other)
    {
        Vector res(lenght);
        for(int i = 0;i<lenght;++i)
            res.data[i]=data[i]-other.data[i];
        return res;
    }

    Vector operator*(Vector const &other)
    {
        Vector res(lenght);
        for(int i = 0;i<lenght;++i)
            res.data[i]=data[i]*other.data[i];
        return res;
    }

    Vector operator/(Vector const &other)
    {
        Vector res(lenght);
        for(int i = 0;i<lenght;++i)
            res.data[i]=data[i]/other.data[i];
        return res;
    }

    bool operator==(Vector &other)
    {
        if(lenght!=other.lenght)
            return 0;
        for(int i = 0;i<lenght;++i)
            if(data[i]!=other.data[i])
                return 0;
        return 1;
    }

    T& operator[](int i)
    {
        return data[i];
    }

    T* get_data()
    {
        return data;
    }

    int get_lenght()
    {
        return lenght;
    }

    void sort_bubble()
    {
        for(int i = 0;i<lenght-1;++i)
            for(int j = 0;j<lenght-1;++j)
                if(data[j]>data[j+1])
                    swap(data[j],data[j+1]);
    }

    void sort_insertion()
    {
        for(int i = 1;i<lenght;++i)
        {
            int j = i-1;
            while(j>=0&&data[j]>data[j+1])
            {
                swap(data[j],data[j+1]);
                --j;
            }
        }
    }

    int part(int l, int r)
    {
        T v = data[(l+r)/2];
        int i = l;
        int j = r;
        while(i<=j)
        {
            while(data[i]<v)
                ++i;
            while(data[j]>v)
                --j;
            if(i>=j)
                break;
            swap(data[i++],data[j--]);
        }
        return j;
    }

    void sort_quick(int l , int r)
    {
        if(l<r)
        {
            int q = part(l,r);
            sort_quick(l,q);
            sort_quick(q+1,r);
        }
    }

    ~Vector()
    {
        delete[] data;
    }

    template <class B> friend std::istream &operator>>(std::istream &in, Vector<B> &V);
    template <class B> friend std::ostream &operator<<(std::ostream &out, Vector<B> &V);

private:
    T *data;
    int lenght;
};

template <class T>
std::istream &operator>>(std::istream &in, Vector<T> &V)
{
    T buf;
    int len;
    in >> len;
    V = Vector<T>(len);
    for (int i = 0; i < len; ++i)
        in >> V.data[i];
    return in;
}

template <class T>
std::ostream &operator<<(std::ostream &out, Vector<T> &V)
{
    for (int i = 0; i < V.lenght; ++i)
        out << V.data[i]<<" ";
    return out;
}

template <class T>
class Matrix
{
public:
    Matrix(int N = 0, int M = 0):n(N),m(M)
    {
        data = new T*[n];
        for(int i = 0;i<n;++i)
            data[i] = new T[m];
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                data[i][j]=0;
    }

    Matrix(Matrix &other):Matrix(other.n,other.m)
    {
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                data[i][j]=other.data[i][j];
    }
    
    Matrix(Vector<T> &vec):Matrix(vec.get_lenght(),1)
    {
        for(int i = 0;i<n;++i)
            data[i][0]=vec[i];
    }

    Matrix &operator=(Matrix const &other)
    {
        if (&other == this)
            return *this;

        for(int i = 0;i<n;++i)
            delete[] data[i];
        delete[] data;
        
        n = other.n;
        m=other.m;
        data = new T*[n];
        for(int i = 0;i<n;++i)
            data[i] = new T[m];
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                data[i][j]=other.data[i][j];
        return *this;
    }

    Matrix operator*(Matrix &other)
    {
        Matrix res(n,other.m);
        for(int i = 0;i<n;++i)
            for(int j = 0;j<other.m;++j)
                for(int k = 0;k<m;++k)
                    res.data[i][j] += data[i][k]*other.data[k][j];
        return res;
    }

    Matrix operator+(Matrix &other)
    {
        Matrix res(n,m);
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                res.data[i][j]=data[i][j]+other.data[i][j];
        return res;
    }

    Matrix operator-(Matrix &other)
    {
        Matrix res(n,m);
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                res.data[i][j]=data[i][j]-other.data[i][j];
        return res;
    }

    bool operator==(Matrix &other)
    {
        if(n!=other.n)
            return 0;
        if(m!= other.m)
            return 0;
        for(int i =0;i<n;++i)
            for(int j = 0;j<m;++j)
                if(data[i][j]!=other.data[i][j])
                    return 0;
        return 1;
    }

    T* operator[](int idx)
    {
        return data[idx];
    }

    int get_n()
    {
        return n;
    }

    int get_m()
    {
        return m;
    }

    int count_num(T val)
    {
        int res=0;
        for(int i = 0;i<n;++i)
            for(int j=0;j<m;++j)
                if(data[i][j]==val)
                    ++res;
        return res;
    }

    template <class B> friend std::istream &operator>>(std::istream &in, Matrix<B> &M);
    template <class B> friend std::ostream &operator<<(std::ostream &out, Matrix<B> &M);

private:
    T** data;
    int n;
    int m;
};

template <class T>
std::istream &operator>>(std::istream &in, Matrix<T> &M)
{
    int n,m;
    in >> n>>m;
    M = Matrix<T>(n,m);
    for(int i =0;i<n;++i)
        for(int j = 0;j<m;++j)
            in>>M.data[i][j];
    return in;
}

template <class T>
std::ostream &operator<<(std::ostream &out, Matrix<T> &M)
{
    for(int i = 0;i<M.n;++i)
    {
        for(int j = 0;j<M.m;++j)
            std::cout<<M.data[i][j]<<" ";
        std::cout<<"\n";
    }
    return out;
}

template <class T>
Matrix<T> operator*(Matrix<T> M, Vector<T> V)
{
    Matrix<T> buf(V);
    return M*buf;
}

template <class T>
Matrix<T> operator*(Vector<T> V, Matrix<T> M)
{
    Matrix<T> buf(V);
    return buf*M;
}
