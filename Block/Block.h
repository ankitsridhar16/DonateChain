#include <cstdint>
#include <iostream>

class Block {

    public:
        std::string prevHash;
        Block(uint_fast32_t nIndexIn, const std::string &sDataIn);
        std::string getHash();
        void mineBlock(uint_fast32_t nDifficulty);

    private:
        uint_fast32_t nIndex;
        uint_fast32_t nNonce;
        std::string sData;
        std::string sHash;
        time_t timeStamp;
        std::string calculateHash() const;

};