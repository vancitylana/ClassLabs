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
