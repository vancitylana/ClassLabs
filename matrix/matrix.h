#pragma once
#include <iostream>

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
