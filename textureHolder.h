#include <raylib.h>
#include <map>
#include <string>

class TextureHolder {
public:
   // This is how clients can access the single instance
   static TextureHolder* getInstance();
   void addTexture (int id, const std::string& path);
   Texture2D* getTexture (int id);
   
protected:
   std::map<int, Texture2D*> idToTexture;

private:
   static TextureHolder* inst_;   // The one, single instance
   TextureHolder() {} // private constructor
   TextureHolder(const TextureHolder&);
   TextureHolder& operator=(const TextureHolder&);
};