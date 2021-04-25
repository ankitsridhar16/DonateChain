#include "../SHA256/SHA256.h"
#include "Block.h"

Block::Block(uint_fast32_t nIndexIn, const std::string &sDataIn) : nIndex(nIndexIn), sData(sDataIn){
    nNonce = -1;
    timeStamp = time(nullptr);
}

std::string Block::getHash() {
    return sHash;
}

void Block::mineBlock(uint_fast32_t nDifficulty){
    char cstr[nDifficulty+1];
    for (uint_fast32_t i=0; i < nDifficulty; ++i){
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    std::string str(cstr);
    do {
        nNonce ++ ; 
        sHash = calculateHash();
    } while(sHash.substr(0, nDifficulty) != str);

    std::cout << "Block successfully Mined : " << sHash << std::endl;
}

inline std::string Block::calculateHash() const {
    std::stringstream outStream;
    ss << nIndex << timeStamp << sData << nNonce << prevHash ;
    return sha256(ss.str());
}