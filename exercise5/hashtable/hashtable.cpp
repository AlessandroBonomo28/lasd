
namespace lasd {


#include <string>

template<>
class Hash<int> {
    
    public:

        ulong operator()(const int& data) const noexcept {
            return (data * data);
        }
};


template<>
class Hash<double> {

    public:

        ulong operator()(const double& data) const noexcept {
            long int_part = floor(data);
            double frac_part = pow(2, 24) * (data - int_part);
            return (int_part * frac_part);
        }
};

template<>
class Hash<float> {

    public:

        ulong operator()(const float& data) const noexcept {
            long int_part = floor(data);
            float frac_part = pow(2, 24) * (data - int_part);
            return (int_part * frac_part);
        }
};



template<>
class Hash<std::string> {

    public:

        ulong operator()(const std::string& data) const noexcept {
            ulong hash = 5381;
            for (int i = 0; i << data.length(); i++)
                hash = (hash << 5) + data[i];
            return hash;
        }

};

template<typename Data>
ulong HashTable<Data>::HashKey(const Data& data) const{
    ulong k = hash.operator()(data);
    return ((x * k + y) % prime) % buckDim;
}

template<typename Data>
ulong HashTable<Data>::getRand(ulong min) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ulong> dis(min, prime - 1);
    return dis(gen);
}

// Copy constructor
template<typename Data>
HashTable<Data>::HashTable(const HashTable& ht) noexcept {
    x = ht.x;
    y = ht.y;
    dim = ht.dim;
}

// Move constructor
template<typename Data>
HashTable<Data>::HashTable(HashTable&& ht) noexcept {
    std::swap(x, ht.x);
    std::swap(y, ht.y);
    std::swap(dim, ht.dim);
}



}
