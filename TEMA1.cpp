#include "lab_m1/TEMA1/TEMA1.h"

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "lab_m1/TEMA1/transform2D.h"
#include "lab_m1/TEMA1/object2D.h"

using namespace std;
using namespace m1;




/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


TEMA1::TEMA1()
{
}


TEMA1::~TEMA1()
{
}







void TEMA1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // pentru initializare generator de numere 
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // initializare date pentru transformari
    

    translate_hexagon_X_1 = 1200;
    translate_hexagon_X_2 = 1200;
    translate_hexagon_X_3 = 1200;
    translate_hexagon_Y = 0;

    translate_stea_X = 0;
    translate_stea_Y = 0;

    scaleX = 1;
    scaleY = 1;


    angularStep = 0;

   
    interval = 2;

    time = 0.0f;

    linie_sus = 0;
    linie_jos = 0;
    linie_mijloc = 0;

    radiani = 0.0f;

    x_mouse = 0.0f;
    y_mouse = 0.0f;

    x_mouse_release = 0.0f;
    y_mouse_release = 0.0f;

    apasare_romb = 0;
    x_apasat_mouse = 0;
    y_apasat_mouse = 0;
    romb_portocaliu = 0;
    romb_albastru = 0;
    romb_mov = 0;
    romb_galben = 0;

    nr_vieti = 3;
    x = 0.0f;
    y = 0.0f;

    centru_hexagon = glm::vec2(0, 0);
    centru_proiectil = glm::vec2(0, 0);
    centru_proiectil_rezultat = glm::vec2(0, 0);
    glm::vec2 centru_romb_sus = glm::vec2(0, 0);
    glm::vec2 centru_romb_mijloc = glm::vec2(0, 0);
    glm::vec2 centru_romb_jos = glm::vec2(0, 0);
    glm::vec2 centru_hexagon_RH = glm::vec2(0, 0);

    coliziune_sus = 0, coliziune_jos = 0, coliziune_mijl= 0, coliziune = 0;
    distanta_centre = 0.0;

    coliziune_HR = 0;
    distanta_centre_HR = 0.0;

    patrat_1_p = 0;
    patrat_2_p = 0;
    patrat_3_p = 0;
    patrat_4_p = 0;
    patrat_5_p = 0;
    patrat_6_p = 0;
    patrat_7_p = 0;
    patrat_8_p = 0;
    patrat_9_p = 0;

    patrat_1_m = 0;
    patrat_2_m = 0;
    patrat_3_m = 0;
    patrat_4_m = 0;
    patrat_5_m = 0;
    patrat_6_m = 0;
    patrat_7_m = 0;
    patrat_8_m = 0;
    patrat_9_m = 0;

    patrat_1_a = 0;
    patrat_2_a = 0;
    patrat_3_a = 0;
    patrat_4_a = 0;
    patrat_5_a = 0;
    patrat_6_a = 0;
    patrat_7_a = 0;
    patrat_8_a = 0;
    patrat_9_a = 0;

    patrat_1_g = 0;
    patrat_2_g = 0;
    patrat_3_g = 0;
    patrat_4_g = 0;
    patrat_5_g = 0;
    patrat_6_g = 0;
    patrat_7_g = 0;
    patrat_8_g = 0;
    patrat_9_g = 0;

    randomColour = 0;
    culoare_a = 0;
    culoare_m = 0;
    culoare_g = 0;
    culoare_p = 0;

    mouse_dreapta = 0;
    scalare_romb_x = 1.0, scalare_romb_y = 1.0;
    scalare_proiectil = 1.0;

    timp_stelute = 0;

    x_resursa_1 = 45.0f;
    y_resursa_1 = 400.0f;
    x_resursa_2 = 100.0f;
    y_resursa_2 = 202.0f;
    x_resursa_3 = 50.0f;
    y_resursa_3 = 100.0f;

    timp_resursa = 0.0f;
    nr_resurse = 0;
    nr_max_resurse = 3;
    interval_resurse = 7.0f;
    resursa = 0;
    contor_stea = 0;

    release_p1_x = 0.0f, release_p1_y = 0.0f, release_p2_x = 0.0f, release_p2_y = 0.0f;
    release_p3_x = 0.0f, release_p3_y = 0.0f, release_p4_x = 0.0f, release_p4_y = 0.0f;
    release_p5_x = 0.0f, release_p5_y = 0.0f, release_p6_x = 0.0f, release_p6_y = 0.0f;
    release_p7_x = 0.0f, release_p7_y = 0.0f, release_p8_x = 0.0f, release_p8_y = 0.0f;
    release_p9_x = 0.0f, release_p9_y = 0.0f; 

    mouse_dr_1 = 0, mouse_dr_2 = 0, mouse_dr_3 = 0;
    mouse_dr_4 = 0, mouse_dr_5 = 0, mouse_dr_6 = 0;
    mouse_dr_7 = 0, mouse_dr_8 = 0, mouse_dr_9 = 0;

    

    {
        /*
        * creare vertecsi pentru dreptunghiul bara rosie
        */
        vector<VertexFormat> vertecsi1
        {
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(20, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(20, 136 , 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 136, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
        };

        /* creare indecsi pentru dreptunghi
         acesta va fi constituit din 2 triunghiuri
         */
        vector<unsigned int> indici1 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        // creare mesh 
        CreateMesh("dreptunghi", vertecsi1, indici1);

        // la fel pentru patrat

        vector<VertexFormat> vertecsi2
        {
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(40, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(40, 40, 0), glm::vec3(0, 1, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 40, 0), glm::vec3(0, 1, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici2 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("patrat", vertecsi2, indici2);

        // creare patrat doar contur 

        // aici setez pozitia (fata de corner)
        glm::vec3 corner_1 = glm::vec3(0, 0, 0);
        // latura patratului
        length = 10.0f;

        Mesh* patrat_c_1 = object2D::CreateSquare("patrat_c_1", corner_1, length, glm::vec3(1, 0, 0));
        AddMeshToList(patrat_c_1);


        // creare patrate micute pentru vieti

        vector<VertexFormat> vertecsi3
        {
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(25, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(25, 25, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 25, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici3 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("patrat_viata", vertecsi3, indici3);


        // creare romb 1

        vector<VertexFormat> vertecsi4
        {
            VertexFormat(glm::vec3(0, -15, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(-7.5, 0, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5, 0, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),

        };

        vector<unsigned int> indici4 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("romb_1", vertecsi4, indici4);

        // creare dreptunghi pt romb 1
        vector<VertexFormat> vertecsi5
        {
            VertexFormat(glm::vec3(0.0f, 0, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 1), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici5 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("dreptunghi_romb_1", vertecsi5, indici5);

        // creare romb 2

        vector<VertexFormat> vertecsi6
        {
            VertexFormat(glm::vec3(0.0f, -15, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(-7.5, 0, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0.0, 15, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 0.0, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici6 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("romb_2", vertecsi6, indici6);

        // creare dreptunghi pt romb 2
        vector<VertexFormat> vertecsi7
        {
            VertexFormat(glm::vec3(0.0f, 0, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 1), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici7 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("dreptunghi_romb_2", vertecsi7, indici7);

        // creare romb 3

        vector<VertexFormat> vertecsi8
        {
            VertexFormat(glm::vec3(0, -15, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(-7.5, 0, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5, 0, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici8 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("romb_3", vertecsi8, indici8);

        // creare dreptunghi pt romb 3
        vector<VertexFormat> vertecsi9
        {
            VertexFormat(glm::vec3(0.0f, 0, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 1), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici9 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("dreptunghi_romb_3", vertecsi9, indici9);

        // creare romb 4

        vector<VertexFormat> vertecsi10
        {
            VertexFormat(glm::vec3(0, -15, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(-7.5, 0.0f, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 0.0, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici10 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("romb_4", vertecsi10, indici10);

        // creare dreptunghi pt romb 4
        vector<VertexFormat> vertecsi11
        {
            VertexFormat(glm::vec3(0.0f, 0, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15, 7.5, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15, 0.0f, 1), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici11 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("dreptunghi_romb_4", vertecsi11, indici11);
    }

        
       

}












void TEMA1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.792, 0.988, 0.78, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




void TEMA1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);

    // desenare dreptunghi
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(22, 22);
    modelMatrix *= transform2D::Scale(3.5, 3.5);
    RenderMesh2D(meshes["dreptunghi"], shaders["VertexColor"], modelMatrix);




    // desenare patrate
    for (int i = 0; i <= 300; i = i + 150) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(120 + i, 380);
        modelMatrix *= transform2D::Scale(2.9, 2.9);
        RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
    }


    for (int i = 0; i <= 300; i = i + 150) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(120 + i, 207);
        modelMatrix *= transform2D::Scale(2.9, 2.9);
        RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i <= 300; i = i + 150) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(120 + i, 25);
        modelMatrix *= transform2D::Scale(2.9, 2.9);
        RenderMesh2D(meshes["patrat"], shaders["VertexColor"], modelMatrix);
    }



    // desenare patrate fara contur
    for (int i = 0; i <= 540; i = i + 180) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(60 + i, 600);
        modelMatrix *= transform2D::Scale(10, 10);
        RenderMesh2D(meshes["patrat_c_1"], shaders["VertexColor"], modelMatrix);
    }

    // desenare patrat viata

    for (int i = 0; i < 150 * nr_vieti; i = i + 150) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(800 + i, 608);
        modelMatrix *= transform2D::Scale(3, 3);
        RenderMesh2D(meshes["patrat_viata"], shaders["VertexColor"], modelMatrix);
    }



    // desenare proiectile

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 650);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 637);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(280, 650);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(280, 637);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(460, 650);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(460, 637);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(640, 650);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(640, 637);
    modelMatrix *= transform2D::Scale(3, 3);
    RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);


    // desenare stele

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(70, 575);
    modelMatrix *= transform2D::Scale(12, 12);
    CreateStar(1, 0, 0.53);
    RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);


    for (int i = 0; i <= 50; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(260 + i, 575);
        modelMatrix *= transform2D::Scale(12, 12);
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i <= 50; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(440 + i, 575);
        modelMatrix *= transform2D::Scale(12, 12);
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i <= 100; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(600 + i, 575);
        modelMatrix *= transform2D::Scale(12, 12);
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
    }


    for (int i = 0; i <= 250; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(800 + i, 575);
        modelMatrix *= transform2D::Scale(12, 12);
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
        
       
    }

    


    // generez resurse pe ecran intamplator
   
    timp_resursa = timp_resursa + deltaTimeSeconds;

    if (timp_resursa > interval_resurse) {
        timp_resursa = 0.0f;
        listaStelute.push_back(std::make_pair(x_resursa_1, y_resursa_1));
        listaStelute.push_back(std::make_pair(x_resursa_2, y_resursa_2));
        listaStelute.push_back(std::make_pair(x_resursa_3, y_resursa_3));

        x_resursa_1 = static_cast<float>(std::rand()) / (RAND_MAX / (1000));
        y_resursa_1 = static_cast<float>(std::rand()) / (RAND_MAX / (700));
        x_resursa_2 = static_cast<float>(std::rand()) / (RAND_MAX / (1000));
        y_resursa_2 = static_cast<float>(std::rand()) / (RAND_MAX / (700));
        x_resursa_3 = static_cast<float>(std::rand()) / (RAND_MAX / (1000));
        y_resursa_3 = static_cast<float>(std::rand()) / (RAND_MAX / (700));

    }

    
    for (const auto& coordonate : listaStelute) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(coordonate.first, coordonate.second);
        modelMatrix *= transform2D::Scale(24, 24);
        CreateStar(1, 0, 0.53);
        if (apasare_stea == 1) {
            for (auto it = listaStelute.begin(); it != listaStelute.end();) {
                float x_steluta = it->first;
                float y_steluta = it->second;

                // Verifică dacă clicul s-a produs în apropierea stelutei
                if (isPointNear(x_mouse, y_mouse, x_steluta, y_steluta, 14.0f)) {
                    // Elimină steluta din vector
                    it = listaStelute.erase(it);
                    apasare_stea = 0;
                    // vreau sa mai adaug inca 4 si atat, dupa ar iesi din ecran
                    if (contor_stea < 200) {
                        listaSteluteEcran.push_back(std::make_pair(1100 + contor_stea, 575));
                    }
                    contor_stea = contor_stea + 50;
                    
                }
                else {
                    ++it;
                    apasare_stea = 0;
                }
            }
        }
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       
    }

    for (const auto& coordonate : listaSteluteEcran) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(coordonate.first, coordonate.second);
        modelMatrix *= transform2D::Scale(12, 12);
        RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
    }
      
      
   
   
   




       // aparitie aleatoare de inamici de culori diferite

       time = time + deltaTimeSeconds;
       if (time > interval) {
           randomPosition = std::rand() % 3;
           randomColour = std::rand() % 4;
           time = 0;

           // le pun pe 1 ca sa marchez ca da, trebuie desenat pe linia asta
           // astfel pot intra in mai multe conditii in aceeasi parcurgere
           if (randomPosition == 0) {
               linie_jos = 1; // -20

           }
           if (randomPosition == 1) {
               linie_mijloc = 1; // -8
           }
           if (randomPosition == 2) {
               linie_sus = 1; // 4
           }
           if (randomColour == 0) {
               culoare_a = 1;
           }
           if (randomColour == 1) {
               culoare_m = 1;
           }
           if (randomColour == 2) {
               culoare_p = 1;
           }
           if (randomColour == 3) {
               culoare_g = 1;
           }
       }

       if (linie_jos == 1) {
           yOffset = 80;  // Prima poziție
           // daca s a ales 0 -> albastru
           if (translate_hexagon_X_1 > 120.0f) {
               translate_hexagon_X_1 -= deltaTimeSeconds * 150;
               centru_hexagon = glm::vec2(1200 - translate_stea_X, yOffset);
               ColiziuneSH(centru_hexagon, centru_proiectil_rezultat);
               coliziune_jos = coliziune;
               if (coliziune_jos == 0) {
                   glm::mat3 modelMatrix = glm::mat3(1);
                   modelMatrix *= transform2D::Translate(translate_hexagon_X_1, yOffset);
                   modelMatrix *= transform2D::Scale(8, 8);
                   CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                   RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                   RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);
               }
               else {
                   modelMatrix = glm::mat3(1);
                   if (scaleX >= 0.0) {
                       scaleX += deltaTimeSeconds * -5;
                       //mentine forma uniforma
                       scaleY = scaleX;
                       modelMatrix *= transform2D::Scale(scaleX, scaleY);
                       CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                       RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);

                   }

               }
           }

           if (translate_hexagon_X_1 > 220.0f && coliziune_jos == 1) {
               translate_hexagon_X_1 = 1200;
               linie_jos = 0;
               coliziune_jos = 0;
               coliziune = 0;
               scalare_proiectil = 1.0f;
               translate_stea_X = 0;
               cout << "coliziune din if jos" << coliziune_jos << endl;
           }

           if (translate_hexagon_X_1 < 120.0f && coliziune_jos == 0) {
               translate_hexagon_X_1 = 1200;
               linie_jos = 0;
               culoare_a = 0;
               nr_vieti--;
               /*if (nr_vieti == 0) {
                   exit(0);
               }*/
           }


       }


       if (linie_mijloc == 1) {
           yOffset = 270; // A doua poziție
           if (translate_hexagon_X_2 > 120) {
               translate_hexagon_X_2 -= deltaTimeSeconds * 150;
               centru_hexagon = glm::vec2(1200 - translate_stea_X, yOffset);
               ColiziuneSH(centru_hexagon, centru_proiectil_rezultat);
               coliziune_mijl = coliziune;
               if (coliziune_mijl == 0) {
                   glm::mat3 modelMatrix = glm::mat3(1);
                   modelMatrix *= transform2D::Translate(translate_hexagon_X_2, yOffset);
                   modelMatrix *= transform2D::Scale(8, 8);
                   CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                   RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                   RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);
               }
               else if (coliziune_mijl == 1) {
                   modelMatrix = glm::mat3(1);
                   if (scaleX >= 0.0) {
                       scaleX += deltaTimeSeconds * -5;
                       //mentine forma uniforma
                       scaleY = scaleX;
                       modelMatrix *= transform2D::Scale(scaleX, scaleY);
                       CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                       RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);

                   }

               }
           }

           if (translate_hexagon_X_2 > 220.0f && coliziune_mijl == 1) {
               translate_hexagon_X_2 = 1200;
               linie_mijloc = 0;
               coliziune = 0;
               coliziune_mijl = 0;
               scalare_proiectil = 1.0f;
               translate_stea_X = 0;
               cout << "coliziune din if mijl" << coliziune << endl;
           }


           if (translate_hexagon_X_2 < 120.0f && coliziune_mijl == 0) {
               translate_hexagon_X_2 = 1200;
               linie_mijloc = 0;
               culoare_a = 0;
               nr_vieti--;
               /*if (nr_vieti == 0) {
                   exit(0);
               }*/

           }

       }

       if (linie_sus == 1) {
           yOffset = 440; // A treia poziție
           if (translate_hexagon_X_3 > 120) {
               translate_hexagon_X_3 -= deltaTimeSeconds * 150;
               centru_hexagon = glm::vec2(1200 - translate_stea_X, yOffset);
               //centru_hexagon_RH = glm::vec2(1200 + translate_hexagon_X_3, yOffset);
               ColiziuneSH(centru_hexagon, centru_proiectil_rezultat);
               //ColiziuneRH(centru_hexagon_RH, centru_romb_sus);
               coliziune_sus = coliziune;
               if (coliziune_sus == 0) {
                   glm::mat3 modelMatrix = glm::mat3(1);
                   modelMatrix *= transform2D::Translate(translate_hexagon_X_3, yOffset);
                   modelMatrix *= transform2D::Scale(8, 8);
                   CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                   RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                   RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);

               }
               else if (coliziune_sus == 1) {
                   modelMatrix = glm::mat3(1);
                   if (scaleX >= 0.0) {
                       scaleX += deltaTimeSeconds * -5;
                       //mentine forma uniforma
                       scaleY = scaleX;
                       modelMatrix *= transform2D::Scale(scaleX, scaleY);
                       CreareHexagon(0, 0.094, 1, 0, 0.652, 1);
                       RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);
                       
                       
                      


                   }

               }
               
           }
           if (translate_hexagon_X_3 > 220.0f && coliziune_sus == 1) {
               translate_hexagon_X_3 = 1200;
               linie_sus = 0;
               coliziune = 0;
               coliziune_sus = 0;
               //scalare_proiectil = 1.0f;
               //translate_stea_X = 0;
               cout << "coliziune din if sus" << coliziune << endl;
           }


           if (translate_hexagon_X_3 < 120.0f  && coliziune_sus == 0) {
               translate_hexagon_X_3 = 1200;
               linie_sus = 0;
               nr_vieti--;
               /*if (nr_vieti == 0) {
                   exit(0);
               }*/
           }
       }

       // verific ce culoare am ales cu mouse-ul

       // pentru primul patrat de contur am portocaliu
       if (x_apasat_mouse >= 20 && x_apasat_mouse <= 100 && y_apasat_mouse <= 660 && y_apasat_mouse >= 560) {
           romb_portocaliu = 1;
       }
       // pentru al doilea patrat de contur am mov
       if (x_apasat_mouse >= 200 && x_apasat_mouse <= 280 && y_apasat_mouse <= 660 && y_apasat_mouse >= 560) {
           romb_mov = 1;
       }
       // pentru al treilea patrat de contur am albastru
       if (x_apasat_mouse >= 380 && x_apasat_mouse <= 460 && y_apasat_mouse <= 660 && y_apasat_mouse >= 560) {
           romb_albastru = 1;
       }
       // pentru al treilea patrat de contur am galben
       if (x_apasat_mouse >= 560 && x_apasat_mouse <= 640 && y_apasat_mouse <= 660 && y_apasat_mouse >= 560) {
           romb_galben = 1;
       }





      // se face translatie dupa coordonatele de deplasare ale mouseului
       if (apasare_romb == 1) {
           if (romb_portocaliu == 1) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (romb_mov == 1) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
           }

           if (romb_albastru == 1) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
           }

           if (romb_galben == 1) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(x_mouse, y_mouse - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
           }
       }
       // se face asezarea rombului la coordonatele la care mouse ul nu mai e apasat
       if (apasare_romb == 2) {

           if (romb_portocaliu == 1) {
               // incadrare in limitele primului patrat
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_1_p = 1;
                   release_p1_x = x_mouse_release;
                   release_p1_y = y_mouse_release;
                   romb_portocaliu = 0;
                   mouse_dr_1 = 0;



                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }



               // incadrare in limite patrat 2
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_2_p = 1;
                   release_p2_x = x_mouse_release;
                   release_p2_y = y_mouse_release;
                   romb_portocaliu = 0;
                   mouse_dr_2 = 0;


                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }



               // incadrare patrat 3
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_3_p = 1;
                   release_p3_x = x_mouse_release;
                   release_p3_y = y_mouse_release;
                   romb_portocaliu = 0;
                   mouse_dr_3 = 0;


               }


               // incadrare patrat 4
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_4_p = 1;
                   mouse_dr_4 = 0;
                   release_p4_x = x_mouse_release;
                   release_p4_y = y_mouse_release;
                   romb_portocaliu = 0;

               }

               // incadrare patrat 5
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_5_p = 1;
                   mouse_dr_5 = 0;
                   release_p5_x = x_mouse_release;
                   release_p5_y = y_mouse_release;
                   romb_portocaliu = 0;
                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }

               // incadrare patrat 6
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_6_p = 1;
                   mouse_dr_6 = 0;
                   release_p6_x = x_mouse_release;
                   release_p6_y = y_mouse_release;
                   romb_portocaliu = 0;

               }

               // incadrare patrat 7
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_7_p = 1;
                   mouse_dr_7 = 0;
                   release_p7_x = x_mouse_release;
                   release_p7_y = y_mouse_release;
                   romb_portocaliu = 0;
               }

               // incadrare patrat 8
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_8_p = 1;
                   mouse_dr_8 = 0;
                   release_p8_x = x_mouse_release;
                   release_p8_y = y_mouse_release;
                   romb_portocaliu = 0;
               }


               // incadrare patrat 9
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   mouse_dr_9 = 0;
                   release_p9_x = x_mouse_release;
                   release_p9_y = y_mouse_release;
                   patrat_9_p = 1;
                   romb_portocaliu = 0;
               }
           }


           if (romb_mov == 1) {

               // incadrare in limitele primului patrat
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_1_m = 1;
                   release_p1_x = x_mouse_release;
                   release_p1_y = y_mouse_release;
                   romb_mov = 0;
                   mouse_dr_1 = 0;



               }

               // incadrare in limite patrat 2
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_2_m = 1;
                   release_p2_x = x_mouse_release;
                   release_p2_y = y_mouse_release;
                   romb_mov = 0;
                   mouse_dr_2 = 0;

               }


               // incadrare patrat 3
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_3_m = 1;
                   release_p3_x = x_mouse_release;
                   release_p3_y = y_mouse_release;
                   romb_mov = 0;
                   mouse_dr_3 = 0;

               }

               // incadrare patrat 4
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_4_m = 1;
                   mouse_dr_4 = 0;
                   release_p4_x = x_mouse_release;
                   release_p4_y = y_mouse_release;
                   romb_mov = 0;

               }

               // incadrare patrat 5
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_5_m = 1;
                   mouse_dr_5 = 0;
                   release_p5_x = x_mouse_release;
                   release_p5_y = y_mouse_release;
                   romb_mov = 0;
                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }

               // incadrare patrat 6
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_6_m = 1;
                   mouse_dr_6 = 0;
                   release_p6_x = x_mouse_release;
                   release_p6_y = y_mouse_release;
                   romb_mov = 0;

               }

               // incadrare patrat 7
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_7_m = 1;
                   mouse_dr_7 = 0;
                   release_p7_x = x_mouse_release;
                   release_p7_y = y_mouse_release;
                   romb_mov = 0;

               }

               // incadrare patrat 8
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_8_m = 1;
                   mouse_dr_8 = 0;
                   release_p8_x = x_mouse_release;
                   release_p8_y = y_mouse_release;
                   romb_mov = 0;

               }


               // incadrare patrat 9
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_9_m = 1;
                   mouse_dr_9 = 0;
                   release_p9_x = x_mouse_release;
                   release_p9_y = y_mouse_release;
                   romb_mov = 0;

               }
           }


           // a + g
           if (romb_albastru == 1) {

               // incadrare in limitele primului patrat
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_1_a = 1;
                   release_p1_x = x_mouse_release;
                   release_p1_y = y_mouse_release;
                   romb_albastru = 0;
                   mouse_dr_1 = 0;



               }

               // incadrare in limite patrat 2
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_2_a = 1;
                   release_p2_x = x_mouse_release;
                   release_p2_y = y_mouse_release;
                   romb_albastru = 0;
                   mouse_dr_2 = 0;

               }


               // incadrare patrat 3
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_3_a = 1;
                   release_p3_x = x_mouse_release;
                   release_p3_y = y_mouse_release;
                   romb_albastru = 0;
                   mouse_dr_3 = 0;

               }

               // incadrare patrat 4
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_4_a = 1;
                   mouse_dr_4 = 0;
                   release_p4_x = x_mouse_release;
                   release_p4_y = y_mouse_release;
                   romb_albastru = 0;

               }

               // incadrare patrat 5
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_5_a = 1;
                   mouse_dr_5 = 0;
                   release_p5_x = x_mouse_release;
                   release_p5_y = y_mouse_release;
                   romb_albastru = 0;
                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }

               // incadrare patrat 6
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_6_a = 1;
                   mouse_dr_6 = 0;
                   release_p6_x = x_mouse_release;
                   release_p6_y = y_mouse_release;
                   romb_albastru = 0;

               }

               // incadrare patrat 7
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_7_a = 1;
                   mouse_dr_7 = 0;
                   release_p7_x = x_mouse_release;
                   release_p7_y = y_mouse_release;
                   romb_albastru = 0;

               }

               // incadrare patrat 8
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_8_a = 1;
                   mouse_dr_8 = 0;
                   release_p8_x = x_mouse_release;
                   release_p8_y = y_mouse_release;
                   romb_albastru = 0;

               }


               // incadrare patrat 9
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_9_a = 1;
                   mouse_dr_9 = 0;
                   release_p9_x = x_mouse_release;
                   release_p9_y = y_mouse_release;
                   romb_albastru = 0;

               }
           }

           if (romb_galben == 1) {

               // incadrare in limitele primului patrat
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_1_g = 1;
                   release_p1_x = x_mouse_release;
                   release_p1_y = y_mouse_release;
                   romb_galben = 0;
                   mouse_dr_1 = 0;



               }

               // incadrare in limite patrat 2
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_2_g = 1;
                   release_p2_x = x_mouse_release;
                   release_p2_y = y_mouse_release;
                   romb_galben = 0;
                   mouse_dr_2 = 0;

               }


               // incadrare patrat 3
               if (y_mouse_release >= 380 && y_mouse_release <= 470 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_3_g = 1;
                   release_p3_x = x_mouse_release;
                   release_p3_y = y_mouse_release;
                   romb_galben = 0;
                   mouse_dr_3 = 0;

               }

               // incadrare patrat 4
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_4_g = 1;
                   mouse_dr_4 = 0;
                   release_p4_x = x_mouse_release;
                   release_p4_y = y_mouse_release;
                   romb_galben = 0;

               }

               // incadrare patrat 5
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_5_g = 1;
                   mouse_dr_5 = 0;
                   release_p5_x = x_mouse_release;
                   release_p5_y = y_mouse_release;
                   romb_galben = 0;
                   // cand pe acea linie am inamic sa iasa proiectil din romb

               }

               // incadrare patrat 6
               if (y_mouse_release >= 207 && y_mouse_release <= 297 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_6_g = 1;
                   mouse_dr_6 = 0;
                   release_p6_x = x_mouse_release;
                   release_p6_y = y_mouse_release;
                   romb_galben = 0;

               }

               // incadrare patrat 7
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 120 && x_mouse_release <= 180) {
                   patrat_7_g = 1;
                   mouse_dr_7 = 0;
                   release_p7_x = x_mouse_release;
                   release_p7_y = y_mouse_release;
                   romb_galben = 0;

               }

               // incadrare patrat 8
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 270 && x_mouse_release <= 330) {
                   patrat_8_g = 1;
                   mouse_dr_8 = 0;
                   release_p8_x = x_mouse_release;
                   release_p8_y = y_mouse_release;
                   romb_galben = 0;

               }


               // incadrare patrat 9
               if (y_mouse_release >= 25 && y_mouse_release <= 115 && x_mouse_release >= 420 && x_mouse_release <= 480) {
                   patrat_9_g = 1;
                   mouse_dr_9 = 0;
                   release_p9_x = x_mouse_release;
                   release_p9_y = y_mouse_release;
                   romb_galben = 0;

               }
           }



       }



       

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 380 && y_apasat_mouse <= 470 && x_apasat_mouse >= 120 && x_apasat_mouse <= 180) {
               mouse_dr_1 = 1;
           }
           
       }

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 380 && y_apasat_mouse <= 470 && x_apasat_mouse >= 270 && x_apasat_mouse <= 330) {
               mouse_dr_2 = 1;
           }
           
       }

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 380 && y_apasat_mouse <= 470 && x_apasat_mouse >= 420 && x_apasat_mouse <= 480) {
               mouse_dr_3 = 1;

           }
       }

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 207 && y_apasat_mouse <= 297 && x_apasat_mouse >= 120 && x_apasat_mouse <= 180) {
               mouse_dr_4 = 1;
           }
       }

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 207 && y_apasat_mouse <= 297 && x_apasat_mouse >= 270 && x_apasat_mouse <= 330) {
               mouse_dr_5 = 1;
           }
       }

       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 207 && y_apasat_mouse <= 297 && x_apasat_mouse >= 420 && x_apasat_mouse <= 480) {
               mouse_dr_6 = 1;
           }
       }


       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 25 && y_apasat_mouse <= 115 && x_apasat_mouse >= 120 && x_apasat_mouse <= 180) {
               mouse_dr_7 = 1;
           }
       }


       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 25 && y_apasat_mouse <= 115 && x_apasat_mouse >= 270 && x_apasat_mouse <= 330) {
               mouse_dr_8 = 1;
           }
       }


       if (mouse_dreapta == 1) {
           if (y_apasat_mouse >= 25 && y_apasat_mouse <= 115 && x_apasat_mouse >= 420 && x_apasat_mouse <= 480) {
               mouse_dr_9 = 1;
           }
       }
           
           
           



       

       if (patrat_1_p == 1 && patrat_1_m != 1) {
           if (linie_sus == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 260, 440, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
                  
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
            if (mouse_dr_1 == 0) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
            }
           // disparitie romb la apasare click dreapta

           if (mouse_dr_1 == 1) {
               if (release_p1_x - 50 <= x_apasat_mouse <= release_p1_x + 50 && release_p1_y - 50 <= y_apasat_mouse <= release_p1_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_1_p = 0;
                       
                       
                      
                   }
                       
               }

           }

           
       }
      

       if (patrat_2_p == 1 && patrat_2_m == 0) {
           if (linie_sus == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 340, 440, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
                   
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_2 == 0) {
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_2 == 1) {
               if (release_p2_x - 50 <= x_apasat_mouse <= release_p2_x + 50 && release_p2_y - 50 <= y_apasat_mouse <= release_p2_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_2_p = 0;
                       
                       
                   }

               }

           }

       }


       if (patrat_3_p == 1 && patrat_3_m == 0) {
           // cand pe acea linie am inamic sa iasa proiectil din romb
           if (linie_sus == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 420, 440, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
          
           if (mouse_dr_3 == 0) {
               
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_3 == 1) {
               if (release_p3_x - 50 <= x_apasat_mouse <= release_p3_x + 50 && release_p3_y - 50 <= y_apasat_mouse <= release_p3_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_3_p = 0;
                       

                   }

               }

           }

       }
      

       if (patrat_4_p == 1 && patrat_4_m == 0) {
           if (linie_mijloc == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 260, 270, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_4 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_4 == 1) {
               if (release_p4_x - 50 <= x_apasat_mouse <= release_p4_x + 50 && release_p4_y - 50 <= y_apasat_mouse <= release_p4_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_4_p = 0;
                       

                   }

               }

           }

       }

       if (patrat_5_p == 1 && patrat_5_m == 0) {
           if (linie_mijloc == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 340, 270, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_5 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_5 == 1) {
               if (release_p5_x - 50 <= x_apasat_mouse <= release_p5_x + 50 && release_p5_y - 50 <= y_apasat_mouse <= release_p5_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_5_p = 0;
                       mouse_dreapta = 0;

                   }

               }

           }

       }


       if (patrat_6_p == 1 && patrat_6_m == 0) {
           // cand pe acea linie am inamic sa iasa proiectil din romb
           if (linie_mijloc == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 420, 270, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_6 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_6 == 1) {
               if (release_p6_x - 50 <= x_apasat_mouse <= release_p6_x + 50 && release_p6_y - 50 <= y_apasat_mouse <= release_p6_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_6_p = 0;
                       mouse_dreapta = 0;

                   }

               }

           }

       }

       if (patrat_7_p == 1 && patrat_7_m == 0) {
           if (linie_jos == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 260, 80, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_7 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_7 == 1) {
               if (release_p7_x - 50 <= x_apasat_mouse <= release_p7_x + 50 && release_p7_y - 50 <= y_apasat_mouse <= release_p7_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_7_p = 0;
                       mouse_dreapta = 0;

                   }

               }

           }

       }

       if (patrat_8_p == 1 && patrat_8_m == 0) {
           if (linie_jos == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 340, 80, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }

           if (mouse_dr_8 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_8 == 1) {
               if (release_p8_x - 50 <= x_apasat_mouse <= release_p8_x + 50 && release_p8_y - 50 <= y_apasat_mouse <= release_p8_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_8_p = 0;
                       mouse_dreapta = 0;

                   }

               }

           }

       }

       if (patrat_9_p == 1 && patrat_9_m == 0) {
           if (linie_jos == 1) {
               centru_proiectil_rezultat = AparitieProiectil(1, 0.38, 0, deltaTimeSeconds, 420, 80, 0);
               // vreau sa dispara proiectilul care a atacat hexagonul
               if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
                   if (scalare_proiectil >= 0.0) {
                       scalare_proiectil += deltaTimeSeconds * -5;
                       modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
                       RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
                   }
               }
               else {
                   RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
               }

           }
           if (mouse_dr_9 == 0) {

               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
               modelMatrix = glm::mat3(1);
               modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
               modelMatrix *= transform2D::Scale(3, 3);
               RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
           }
           if (mouse_dr_9 == 1) {
               if (release_p9_x - 50 <= x_apasat_mouse <= release_p9_x + 50 && release_p9_y - 50 <= y_apasat_mouse <= release_p9_y + 50) {
                   if (scalare_romb_x >= 0.0) {
                       scalare_romb_x += deltaTimeSeconds * -0.2;
                       scalare_romb_y = scalare_romb_x;
                       modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
                       modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
                       RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
                       RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
                       patrat_9_p = 0;
                       mouse_dreapta = 0;

                   }

               }

           }

       }

       //if (patrat_1_m == 1 && patrat_1_p != 1) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 260, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_1 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //        //centru_romb_sus = glm::vec2(x_mouse_release, y_mouse_release);
       //        //if (coliziune_HR == 1) {
       //        //    cout << "coliziune HR pe 1" << endl;
       //        //    modelMatrix = glm::mat3(1);
       //        //    if (scaleX >= 0.0) {
       //        //        scaleX += deltaTimeSeconds * -5;
       //        //        //mentine forma uniforma
       //        //        scaleY = scaleX;
       //        //        modelMatrix *= transform2D::Scale(scaleX, scaleY);
       //        //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);

       //        //    }
       //        //}
       //    }
       //    // disparitie romb la apasare click dreapta

       //    if (mouse_dr_1 == 1) {
       //        if (release_p1_x - 50 <= x_apasat_mouse <= release_p1_x + 50 && release_p1_y - 50 <= y_apasat_mouse <= release_p1_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_1_m = 0;



       //            }

       //        }

       //    }


       //}


       //if (patrat_2_m == 1 && patrat_2_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 340, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_2 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_2 == 1) {
       //        if (release_p2_x - 50 <= x_apasat_mouse <= release_p2_x + 50 && release_p2_y - 50 <= y_apasat_mouse <= release_p2_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_2_m = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_3_m == 1 && patrat_3_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 420, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_3 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_3 == 1) {
       //        if (release_p3_x - 50 <= x_apasat_mouse <= release_p3_x + 50 && release_p3_y - 50 <= y_apasat_mouse <= release_p3_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_3_m = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_4_m == 1 && patrat_4_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 260, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_4 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_4 == 1) {
       //        if (release_p4_x - 50 <= x_apasat_mouse <= release_p4_x + 50 && release_p4_y - 50 <= y_apasat_mouse <= release_p4_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_4_m = 0;


       //            }

       //        }

       //    }

       //}

       //if (patrat_5_m == 1 && patrat_5_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 340, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_5 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_5 == 1) {
       //        if (release_p5_x - 50 <= x_apasat_mouse <= release_p5_x + 50 && release_p5_y - 50 <= y_apasat_mouse <= release_p5_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_5_m = 0;
       //                

       //            }

       //        }

       //    }

       //}


       //if (patrat_6_m == 1 && patrat_6_p == 0) {
       //    // cand pe acea linie am inamic sa iasa proiectil din romb
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 420, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_6 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_6 == 1) {
       //        if (release_p6_x - 50 <= x_apasat_mouse <= release_p6_x + 50 && release_p6_y - 50 <= y_apasat_mouse <= release_p6_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_6_m = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_7_m == 1 && patrat_7_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 260, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_7 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_7 == 1) {
       //        if (release_p7_x - 50 <= x_apasat_mouse <= release_p7_x + 50 && release_p7_y - 50 <= y_apasat_mouse <= release_p7_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_7_m = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_8_m == 1 && patrat_8_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 340, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_8 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_8 == 1) {
       //        if (release_p8_x - 50 <= x_apasat_mouse <= release_p8_x + 50 && release_p8_y - 50 <= y_apasat_mouse <= release_p8_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_8_m = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_9_m == 1 && patrat_9_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0.612, 0, 1, deltaTimeSeconds, 420, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_9 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_9 == 1) {
       //        if (release_p9_x - 50 <= x_apasat_mouse <= release_p9_x + 50 && release_p9_y - 50 <= y_apasat_mouse <= release_p9_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);
       //                patrat_9_m = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}



       //if (patrat_1_a == 1 && patrat_1_p != 1) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 260, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_1 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //        //centru_romb_sus = glm::vec2(x_mouse_release, y_mouse_release);
       //        //if (coliziune_HR == 1) {
       //        //    cout << "coliziune HR pe 1" << endl;
       //        //    modelMatrix = glm::mat3(1);
       //        //    if (scaleX >= 0.0) {
       //        //        scaleX += deltaTimeSeconds * -5;
       //        //        //mentine forma uniforma
       //        //        scaleY = scaleX;
       //        //        modelMatrix *= transform2D::Scale(scaleX, scaleY);
       //        //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);

       //        //    }
       //        //}
       //    }
       //    // disparitie romb la apasare click dreapta

       //    if (mouse_dr_1 == 1) {
       //        if (release_p1_x - 50 <= x_apasat_mouse <= release_p1_x + 50 && release_p1_y - 50 <= y_apasat_mouse <= release_p1_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_1_a = 0;



       //            }

       //        }

       //    }


       //}


       //if (patrat_2_a == 1 && patrat_2_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 340, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_2 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_2 == 1) {
       //        if (release_p2_x - 50 <= x_apasat_mouse <= release_p2_x + 50 && release_p2_y - 50 <= y_apasat_mouse <= release_p2_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_2_a = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_3_a == 1 && patrat_3_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 420, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_3 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_3 == 1) {
       //        if (release_p3_x - 50 <= x_apasat_mouse <= release_p3_x + 50 && release_p3_y - 50 <= y_apasat_mouse <= release_p3_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_3_a = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_4_a == 1 && patrat_4_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 260, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_4 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_4 == 1) {
       //        if (release_p4_x - 50 <= x_apasat_mouse <= release_p4_x + 50 && release_p4_y - 50 <= y_apasat_mouse <= release_p4_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_4_a = 0;


       //            }

       //        }

       //    }

       //}

       //if (patrat_5_a == 1 && patrat_5_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 340, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_5 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_5 == 1) {
       //        if (release_p5_x - 50 <= x_apasat_mouse <= release_p5_x + 50 && release_p5_y - 50 <= y_apasat_mouse <= release_p5_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_5_a = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_6_a == 1 && patrat_6_p == 0) {
       //    // cand pe acea linie am inamic sa iasa proiectil din romb
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 420, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_6 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_6 == 1) {
       //        if (release_p6_x - 50 <= x_apasat_mouse <= release_p6_x + 50 && release_p6_y - 50 <= y_apasat_mouse <= release_p6_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_6_a = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_7_a == 1 && patrat_7_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 260, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_7 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_7 == 1) {
       //        if (release_p7_x - 50 <= x_apasat_mouse <= release_p7_x + 50 && release_p7_y - 50 <= y_apasat_mouse <= release_p7_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_7_a = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_8_a == 1 && patrat_8_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 340, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_8 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_8 == 1) {
       //        if (release_p8_x - 50 <= x_apasat_mouse <= release_p8_x + 50 && release_p8_y - 50 <= y_apasat_mouse <= release_p8_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_8_a = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_9_a == 1 && patrat_9_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(0, 0.094, 1, deltaTimeSeconds, 420, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_9 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_9 == 1) {
       //        if (release_p9_x - 50 <= x_apasat_mouse <= release_p9_x + 50 && release_p9_y - 50 <= y_apasat_mouse <= release_p9_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_9_a = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_1_g == 1 && patrat_1_p != 1) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 260, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_1 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //        //centru_romb_sus = glm::vec2(x_mouse_release, y_mouse_release);
       //        //if (coliziune_HR == 1) {
       //        //    cout << "coliziune HR pe 1" << endl;
       //        //    modelMatrix = glm::mat3(1);
       //        //    if (scaleX >= 0.0) {
       //        //        scaleX += deltaTimeSeconds * -5;
       //        //        //mentine forma uniforma
       //        //        scaleY = scaleX;
       //        //        modelMatrix *= transform2D::Scale(scaleX, scaleY);
       //        //        RenderMesh2D(meshes["romb_2"], shaders["VertexColor"], modelMatrix);
       //        //        RenderMesh2D(meshes["dreptunghi_romb_2"], shaders["VertexColor"], modelMatrix);

       //        //    }
       //        //}
       //    }
       //    // disparitie romb la apasare click dreapta

       //    if (mouse_dr_1 == 1) {
       //        if (release_p1_x - 50 <= x_apasat_mouse <= release_p1_x + 50 && release_p1_y - 50 <= y_apasat_mouse <= release_p1_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p1_x, release_p1_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_3"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_3"], shaders["VertexColor"], modelMatrix);
       //                patrat_1_g = 0;



       //            }

       //        }

       //    }


       //}


       //if (patrat_2_g == 1 && patrat_2_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 340, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }

       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_2 == 0) {
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_2 == 1) {
       //        if (release_p2_x - 50 <= x_apasat_mouse <= release_p2_x + 50 && release_p2_y - 50 <= y_apasat_mouse <= release_p2_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p2_x, release_p2_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_2_g = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_3_g == 1 && patrat_3_p == 0) {
       //    if (linie_sus == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 420, 440);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_sus == 1 && coliziune_mijl == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_3 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_3 == 1) {
       //        if (release_p3_x - 50 <= x_apasat_mouse <= release_p3_x + 50 && release_p3_y - 50 <= y_apasat_mouse <= release_p3_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p3_x, release_p3_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_3_g = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_4_g == 1 && patrat_4_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 260, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_4 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_4 == 1) {
       //        if (release_p4_x - 50 <= x_apasat_mouse <= release_p4_x + 50 && release_p4_y - 50 <= y_apasat_mouse <= release_p4_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p4_x, release_p4_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_4_g = 0;


       //            }

       //        }

       //    }

       //}

       //if (patrat_5_g == 1 && patrat_5_p == 0) {
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 340, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_5 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_5 == 1) {
       //        if (release_p5_x - 50 <= x_apasat_mouse <= release_p5_x + 50 && release_p5_y - 50 <= y_apasat_mouse <= release_p5_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p5_x, release_p5_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_5_g = 0;


       //            }

       //        }

       //    }

       //}


       //if (patrat_6_g == 1 && patrat_6_p == 0) {
       //    // cand pe acea linie am inamic sa iasa proiectil din romb
       //    if (linie_mijloc == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 420, 270);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_mijl == 1 && coliziune_sus == 0 && coliziune_jos == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_6 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_6 == 1) {
       //        if (release_p6_x - 50 <= x_apasat_mouse <= release_p6_x + 50 && release_p6_y - 50 <= y_apasat_mouse <= release_p6_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p6_x, release_p6_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_6_g = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_7_g == 1 && patrat_7_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 260, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_7 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_7 == 1) {
       //        if (release_p7_x - 50 <= x_apasat_mouse <= release_p7_x + 50 && release_p7_y - 50 <= y_apasat_mouse <= release_p7_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p7_x, release_p7_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_7_g = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_8_g == 1 && patrat_8_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 340, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_8 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_8 == 1) {
       //        if (release_p8_x - 50 <= x_apasat_mouse <= release_p8_x + 50 && release_p8_y - 50 <= y_apasat_mouse <= release_p8_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p8_x, release_p8_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_8_g = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}

       //if (patrat_9_g == 1 && patrat_9_p == 0) {
       //    if (linie_jos == 1) {
       //        centru_proiectil_rezultat = AparitieProiectil(1, 0.98, 0, deltaTimeSeconds, 420, 80);
       //        // vreau sa dispara proiectilul care a atacat hexagonul
       //        if (coliziune_jos == 1 && coliziune_sus == 0 && coliziune_mijl == 0) {
       //            if (scalare_proiectil >= 0.0) {
       //                scalare_proiectil += deltaTimeSeconds * -5;
       //                modelMatrix *= transform2D::Scale(scalare_proiectil, scalare_proiectil);
       //                RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //            }
       //        }
       //        else {
       //            RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
       //        }

       //    }
       //    if (mouse_dr_9 == 0) {

       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //        modelMatrix = glm::mat3(1);
       //        modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //        modelMatrix *= transform2D::Scale(3, 3);
       //        RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //    }
       //    if (mouse_dr_9 == 1) {
       //        if (release_p9_x - 50 <= x_apasat_mouse <= release_p9_x + 50 && release_p9_y - 50 <= y_apasat_mouse <= release_p9_y + 50) {
       //            if (scalare_romb_x >= 0.0) {
       //                scalare_romb_x += deltaTimeSeconds * -0.2;
       //                scalare_romb_y = scalare_romb_x;
       //                modelMatrix *= transform2D::Translate(release_p9_x, release_p9_y - 8);
       //                modelMatrix *= transform2D::Scale(scalare_romb_x, scalare_romb_y);
       //                RenderMesh2D(meshes["romb_4"], shaders["VertexColor"], modelMatrix);
       //                RenderMesh2D(meshes["dreptunghi_romb_4"], shaders["VertexColor"], modelMatrix);
       //                patrat_9_g = 0;
       //                mouse_dreapta = 0;

       //            }

       //        }

       //    }

       //}
}










void TEMA1::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    unsigned int VBO = 0;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO = 0;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

   
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    glBindVertexArray(0);

    if (GetOpenGLError() == GL_INVALID_OPERATION)
    {
        cout << "\t[NOTE] : For students : DON'T PANIC! This error should go away when completing the tasks." << std::endl;
        cout << "\t[NOTE] : For developers : This happens because OpenGL core spec >=3.1 forbids null VAOs." << std::endl;
    }
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
}

// functie pentru a detecta daca un punct se afla aproape de alt punct 

bool TEMA1::isPointNear(float x, float y, float targetX, float targetY, float distanceThreshold) {
    float distance = std::sqrt((x - targetX) * (x - targetX) + (y - targetY) * (y - targetY));
    return distance <= distanceThreshold;
}

// functie pentru creare hexagon

 
void TEMA1::CreareHexagon(float R1, float G1, float B1, float R2, float G2, float B2) {
    // pentru hexagonul mare
    vector<VertexFormat> vertecsi13
    {
    VertexFormat(glm::vec3(0 , 5.97  , 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),     // C - 0
    VertexFormat(glm::vec3(-5.29, 2.78, 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),   // D -  1
    VertexFormat(glm::vec3(-5.18, -2.98, 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),  // E - 2
    VertexFormat(glm::vec3(0, -5.97 , 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),    // F - 3
    VertexFormat(glm::vec3(5.18 , -2.98, 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),    // B - 4
    VertexFormat(glm::vec3(5.28, 2.8, 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),    // G - 5
    VertexFormat(glm::vec3(0.0, 0.0, 2), glm::vec3(R1, G1, B1), glm::vec3(0.2, 0.8, 0.6)),    // A - 6
    };

    vector<unsigned int> indici13 =
    {
        // pentru hexagonul mare
        6, 0, 1,    // ACD
        6, 1, 2,    // ADE
        6, 2, 3,    // AEF
        6, 3, 4,    // AFB
        6, 4, 5,    // ABG
        6, 5, 0,    // AGC
    };

    /*Mesh* mesh_hexagon = new Mesh("hexagon_mare");
    mesh_hexagon->InitFromData(vertecsi13, indici13);
    meshes[mesh_hexagon->GetMeshID()] = mesh_hexagon;*/

    CreateMesh("hexagon_mare", vertecsi13, indici13);



    vector<VertexFormat> vertecsi14
    {
        // pentru hexagonul mic din interior 
        VertexFormat(glm::vec3(0, 4, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),       // H - 7 0
        VertexFormat(glm::vec3(-3.57, 2.03, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),   // I -  8 1
        VertexFormat(glm::vec3(-3.57, -1.95, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),  // J - 9 2
        VertexFormat(glm::vec3(0, -4, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),      // K - 10 3
        VertexFormat(glm::vec3(3.54, -2.03, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),   // M - 11 4
        VertexFormat(glm::vec3(3.5, 2.03, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),    // L - 12 5
        VertexFormat(glm::vec3(0.0, 0.0, 3), glm::vec3(R2, G2, B2), glm::vec3(0.2, 0.8, 0.6)),    // A - 6

    };

    vector<unsigned int> indici14 =
    {
        // pentru hexagonul mic
        6, 0, 1,    // AHI
        6, 1, 2,    // AIJ
        6, 2, 3,    // AJK
        6, 3, 4,    // AKM
        6, 4, 5,    // AML
        6, 5, 0,    // ALH

    };

    CreateMesh("hexagon_mic", vertecsi14, indici14);

    /*Mesh* mesh_hexagon_mic = new Mesh("hexagon_mic");
    mesh_hexagon_mic->InitFromData(vertecsi14, indici14);
    meshes[mesh_hexagon_mic->GetMeshID()] = mesh_hexagon_mic;*/
}


// functie pentru creare stea

void TEMA1::CreateStar(float R, float G, float B) {
    // desenare stea
    vector<VertexFormat> vertecsi12
    {
        // prima data punctele exterioare (de pe cerc)
        VertexFormat(glm::vec3(0.0, 2.00, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),     // C - 0
        VertexFormat(glm::vec3(-1.91, 0.6, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),   // G -  1
        VertexFormat(glm::vec3(-1.43, -1.4, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // D - 2
        VertexFormat(glm::vec3(1.4, -1.43, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),    // E - 3
        VertexFormat(glm::vec3(1.91, 0.6, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),    // F - 4
        // coordonatele interioare
        VertexFormat(glm::vec3(-0.59, 0.6, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // H - 5
        VertexFormat(glm::vec3(-0.86, 0.6, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // J - 6
        VertexFormat(glm::vec3(-0.02, -0.55, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // K - 7                                                                                          
        VertexFormat(glm::vec3(0.84, -0.04, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // L - 8                                                                                            
        VertexFormat(glm::vec3(0.57, 0.9, 1), glm::vec3(R, G, B), glm::vec3(0.2, 0.8, 0.6)),  // I - 9                                                                                            
    };
    vector<unsigned int> indici12 =
    {
       1, 7, 4,      // GKF
       0, 2, 7,      // CDK
       0, 7, 3       // CKE


    };

    CreateMesh("stea", vertecsi12, indici12);
}

// functie aparitie inamici
glm::vec2 TEMA1::AparitieProiectil(float R, float G, float B, float deltaTimeSeconds, float x, float y, float radiani) {
    CreateStar(R, G, B);
    translate_stea_X += deltaTimeSeconds * 150.0f;
    centru_proiectil = glm::vec2(x + translate_stea_X, y);
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x, y);
    modelMatrix *= transform2D::Translate(translate_stea_X, 0.0f);
    modelMatrix *= transform2D::Scale(20, 20);
    radiani -= deltaTimeSeconds * 3;
    modelMatrix *= transform2D::Rotate(radiani);
    
   

    return centru_proiectil;
}

// fac mai multe functii care sa faca sa dispara chestii dupa modelul asteia
void TEMA1::DisparitieMesh(float deltaTimeSeconds) {
    modelMatrix = glm::mat3(1);
    // sa schimbi hardocadarea in parametri aici
    //modelMatrix *= transform2D::Translate(700, 400);
    //modelMatrix *= transform2D::Scale(3, 3);
    if (scaleX >= 0.0) {
       scaleX += deltaTimeSeconds * -0.2;
       //mentine forma uniforma
       scaleY = scaleX;
       modelMatrix *= transform2D::Scale(scaleX, scaleY);
       //RenderMesh2D(meshes["patrat_viata"], shaders["VertexColor"], modelMatrix);
       
    }
}

void TEMA1::ColiziuneSH(glm::vec2 centru_hexagon, glm::vec2 centru_proiectil_rezultat) {
    distanta_centre = glm::distance(centru_hexagon, centru_proiectil_rezultat);
    if (distanta_centre != 0 && distanta_centre < 8) {
        // marchez ca am detectat coliziune
        coliziune = 1;
       
    }
    
    
}


//void TEMA1::ColiziuneRH(glm::vec2 centru_hexagon, glm::vec2 centru_romb_sus) {
//    distanta_centre_HR = glm::distance(centru_hexagon, centru_romb_sus);
//    cout << distanta_centre_HR << endl;
//    //cout << centru_hexagon[0] << endl;
//    if (distanta_centre_HR != 0 && distanta_centre < 21) {
//        // marchez ca am detectat coliziune
//        coliziune_HR = 1;
//        
//
//    }
//
//
//}


void TEMA1::FrameEnd()
{
    //DrawCoordinateSystem();
}


void TEMA1::DrawScene(glm::mat3 visMatrix)
{
   
}




void TEMA1::OnInputUpdate(float deltaTime, int mods)
{
}


void TEMA1::OnKeyPress(int key, int mods)
{
}


void TEMA1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void TEMA1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    glm::ivec2 resolution = window->GetResolution();
    x_mouse = mouseX;
    y_mouse = resolution.y - mouseY;
    
    
    

   
   
}


void TEMA1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // apasare click stanga mouse pt drag and drop
    if (button == 1) {
        apasare_romb = 1;
        apasare_stea = 1;
        
        glm::ivec2 resolution = window->GetResolution();
        x_apasat_mouse = mouseX;
        y_apasat_mouse = resolution.y - mouseY;
    }

    // apasare dreapta mouse pt disparitie romb
    else if (button == 2) {
        mouse_dreapta = 1;
        glm::ivec2 resolution = window->GetResolution();
        x_apasat_mouse = mouseX;
        y_apasat_mouse = resolution.y - mouseY;
        
    }
   
    
   
   



   
    
}


void TEMA1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    apasare_romb = 2;
    glm::ivec2 resolution = window->GetResolution();
    x_mouse_release = mouseX;
    y_mouse_release = resolution.y - mouseY;
    

}


void TEMA1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


