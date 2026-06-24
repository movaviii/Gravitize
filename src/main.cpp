#include <Geode/Geode.hpp>
#include <Geode/modify/EffectGameObject.hpp>

#include <cstdlib>

using namespace geode::prelude;

class $modify(GravitizeEffectGameObject, EffectGameObject) {
    void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) {
        constexpr size_t GRAVITY_IDX = 148;
        constexpr int GRAVITY_OBJECT_ID = 2066;

        bool restore = false;
        float gravity = 1.f;

        if (values.size() > GRAVITY_IDX && exists.size() > GRAVITY_IDX && exists[GRAVITY_IDX]
            && values.size() > 1 && std::atoi(values[1].c_str()) == GRAVITY_OBJECT_ID) {
            char* end = nullptr;
            gravity = std::strtof(values[GRAVITY_IDX].c_str(), &end);
            restore = end != values[GRAVITY_IDX].c_str();
        }

        EffectGameObject::customObjectSetup(values, exists);

        if (restore) m_gravityValue = gravity;
    }
};
