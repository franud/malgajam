#include <raylib.h>
#include <map>
#include <memory>
#include <string>

namespace Textures{
    enum ID {Landscape, Player, Bullet};
}

class TextureHolder{
    private:
    std::map<Textures::ID, std::unique_ptr<Texture2D>> textureMap;
    
    public:
    void load(Textures::ID id, const std::string& filename);
};
