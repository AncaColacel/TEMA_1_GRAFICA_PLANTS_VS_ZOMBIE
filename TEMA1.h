#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class TEMA1 : public gfxc::SimpleScene
    {
     public:
        struct ViewportSpace
        {
            ViewportSpace() : x(0), y(0), width(1), height(1) {}
            ViewportSpace(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        struct LogicSpace
        {
            LogicSpace() : x(0), y(0), width(1), height(1) {}
            LogicSpace(float x, float y, float width, float height)
                : x(x), y(y), width(width), height(height) {}
            float x;
            float y;
            float width;
            float height;
        };

     public:
        TEMA1();
        ~TEMA1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void DrawScene(glm::mat3 visMatrix);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void drawRandomHexagon();
        //void TranslateRotate(string mesh, float deltaTimeSeconds, float translate);

        // Sets the logic space and view space
        // logicSpace: { x, y, width, height }
        // viewSpace: { x, y, width, height }
        glm::mat3 VisualizationTransf2D(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);
        glm::mat3 VisualizationTransf2DUnif(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);
        void SetViewportArea(const ViewportSpace& viewSpace, glm::vec3 colorColor = glm::vec3(0), bool clear = true);
        void CreateStar(float R, float G, float B);
        glm::vec2 AparitieProiectil(float R, float G, float B, float deltaTimeSeconds, float x, float y);
        void DisparitieMesh(float deltaTimeSeconds);
        void ColiziuneSH(glm::vec2 centru_hexagon, glm::vec2 centru_proiectil_rezultat);
        void CreareHexagon(float R1, float G1, float B1, float R2, float G2, float B2);
        float RandomFloat(float min, float max);
        bool isPointNear(float x, float y, float targetX, float targetY, float distanceThreshold);
        void ColiziuneRH(glm::vec2 centru_hexagon, glm::vec2 centru_romb_rezultat);
       
        
        
        

      

     protected:
        float length;
        ViewportSpace viewSpace;
        LogicSpace logicSpace;
        glm::mat3 modelMatrix, visMatrix;
        float time;
        int interval;
        int randomPosition;
        int randomColour;
        int linie_sus;
        int linie_mijloc;
        int linie_jos;
        float  translate_hexagon_X_1, translate_hexagon_Y, scaleX, scaleY, angularStep, translate_hexagon_X_2, translate_hexagon_X_3;
        float translate_hexagon_X_1_2, translate_hexagon_X_2_2, translate_hexagon_X_3_2;
        float radiani, translate_stea_X, translate_stea_Y;
        float yOffset;
        float x_mouse, y_mouse;
        float x_mouse_release, y_mouse_release;
        int apasare_romb;
        float y_logic;
        int romb_portocaliu, romb_galben, romb_albastru, romb_mov;
        float x_apasat_mouse, y_apasat_mouse;
        int nr_vieti;
        float x, y;
        glm::vec2 centru_hexagon;
        glm::vec2 centru_proiectil;
        float distanta_centre;
        int coliziune;
        int patrat_1_p, patrat_2_p, patrat_3_p, patrat_4_p, patrat_5_p, patrat_6_p, patrat_7_p, patrat_8_p, patrat_9_p;
        int patrat_1_m, patrat_2_m, patrat_3_m, patrat_4_m, patrat_5_m, patrat_6_m, patrat_7_m, patrat_8_m, patrat_9_m;
        int patrat_1_a, patrat_2_a, patrat_3_a, patrat_4_a, patrat_5_a, patrat_6_a, patrat_7_a, patrat_8_a, patrat_9_a;
        glm::vec2 centru_proiectil_rezultat;
        glm::vec2 centru_romb_sus;
        glm::vec2 centru_romb_mijloc;
        glm::vec2 centru_romb_jos;
        glm::vec2 centru_hexagon_RH;
        int culoare_a, culoare_m, culoare_p, culoare_g;
        int mouse_dreapta;
        int mouse_dr_1, mouse_dr_2, mouse_dr_3;
        int mouse_dr_4, mouse_dr_5, mouse_dr_6;
        int mouse_dr_7, mouse_dr_8, mouse_dr_9;
        float scalare_romb_x, scalare_romb_y;
        float scalare_proiectil;
        int timp_stelute;
        float timp_resursa;
        int nr_resurse, nr_max_resurse;
        float interval_resurse;
        int resursa;
        float x_resursa_1, y_resursa_1, x_resursa_2, y_resursa_2, x_resursa_3, y_resursa_3;
        std::vector<std::pair<float, float>> listaStelute;
        std::vector<std::pair<float, float>> listaSteluteEcran;
        int apasare_stea;
        int contor_stea;
        float release_p1_x, release_p1_y, release_p2_x, release_p2_y, release_p3_x, release_p3_y;
        float  release_p4_x, release_p4_y, release_p5_x, release_p5_y, release_p6_x, release_p6_y;
        float  release_p7_x, release_p7_y, release_p8_x, release_p8_y, release_p9_x, release_p9_y;
        float distanta_centre_HR;
        int coliziune_HR;
        float scalare_romb;

    };
}   // namespace m1
