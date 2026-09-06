#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ==================== PART A ====================
// unique_ptr : Exclusive Texture Ownership

class Texture {
private:
    string name;
    int width;
    int height;

public:
    Texture(string n, int w, int h) {
        name = n;
        width = w;
        height = h;

        cout << "[Texture Loaded]" << endl;
    }

    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    void display() const {
        cout << "Texture: " << name << endl;
        cout << "Dimensions: " << width << " x " << height << endl;
    }
};


// ==================== PART B ====================
// shared_ptr : Shared Shader Ownership

class Shader {
private:
    string name;
    string type;

public:
    Shader(string n, string t) {
        name = n;
        type = t;

        cout << "[Shader Compiled]" << endl;
    }

    ~Shader() {
        cout << "[Shader Destroyed]" << endl;
    }

    int getReferenceCount(shared_ptr<Shader> shader) {
        return shader.use_count();
    }
};


// ==================== PART C ====================
// weak_ptr : Non-Owning AudioClip Observer

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(string n, double d) {
        name = n;
        duration = d;
    }

    ~AudioClip() {
        cout << "[AudioClip Unloaded]" << endl;
    }

    string getName() const {
        return name;
    }
};


// ==================== MAIN ====================

int main() {

    // ==========================================
    // PART A : unique_ptr
    // ==========================================

    cout << "\n--- PART A : unique_ptr ---" << endl;

    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    tex1->display();

    // unique_ptr<Texture> tex2 = tex1;
    // Error: unique_ptr cannot be copied

    unique_ptr<Texture> tex2 = move(tex1);

    cout << "tex1 is null: "
         << (tex1 == nullptr ? "YES" : "NO") << endl;


    // ==========================================
    // PART B : shared_ptr
    // ==========================================

    cout << "\n--- PART B : shared_ptr ---" << endl;

    auto shader = make_shared<Shader>("main_vert", "vertex");

    cout << "Ref count: " << shader.use_count() << endl;

    {
        auto rendererRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;

        auto editorRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;
    }

    cout << "Ref count: " << shader.use_count() << endl;


    // ==========================================
    // PART C : weak_ptr
    // ==========================================

    cout << "\n--- PART C : weak_ptr ---" << endl;

    auto audio = make_shared<AudioClip>("explosion", 3.5);

    weak_ptr<AudioClip> observer = audio;

    if (auto clip = observer.lock()) {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    audio.reset();

    if (observer.expired()) {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}
