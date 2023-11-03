#include "lab_m1/TEMA1/TEMA1.h"

#include <vector>
#include <iostream>

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

// declare variabile
float  translate_hexagon_X, translate_hexagon_Y, scaleX, scaleY, angularStep;
float radiani, translate_stea_X, translate_stea_Y;

void TEMA1::Init()
{
    auto camera = GetSceneCamera();
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // initializare date pentru transformari
    

    translate_hexagon_X = 0;
    translate_hexagon_Y = 0;

    translate_stea_X = 0;
    translate_stea_Y = 0;

    scaleX = 1;
    scaleY = 1;


    angularStep = 0;

    

    {
        /*
       * creare vertecsi pentru dreptunghiul bara rosie
       */
        vector<VertexFormat> vertecsi1
        {
            VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(20, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(20, 136, 0), glm::vec3(1, 0, 0), glm::vec3(0.2, 0.8, 0.6)),
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

        // creare patrat doar contur 1)

        // aici setez pozitia (fata de corner)
        glm::vec3 corner_1 = glm::vec3(-44, 18, 0);
        // latura patratului
        length = 10.0f;

        Mesh* patrat_c_1 = object2D::CreateSquare("patrat_c_1", corner_1, length, glm::vec3(1, 0, 0));
        AddMeshToList(patrat_c_1);

        // creare patrat doar contur 2)

        // aici setez pozitia (fata de corner)
        glm::vec3 corner_2 = glm::vec3(-30, 18, 0);
        // latura patratului
        length = 10.0f;

        Mesh* patrat_c_2 = object2D::CreateSquare("patrat_c_2", corner_2, length, glm::vec3(1, 0, 0));
        AddMeshToList(patrat_c_2);

        // creare patrat doar contur 3)

        // aici setez pozitia (fata de corner) 
        glm::vec3 corner_3 = glm::vec3(-16, 18, 0);
        // latura patratului
        length = 10.0f;

        Mesh* patrat_c_3 = object2D::CreateSquare("patrat_c_3", corner_3, length, glm::vec3(1, 0, 0));
        AddMeshToList(patrat_c_3);

        // creare patrat doar contur

        // aici setez pozitia (fata de corner) 4)
        glm::vec3 corner_4 = glm::vec3(-2, 18, 0);
        // latura patratului
        length = 10.0f;

        Mesh* patrat_c_4 = object2D::CreateSquare("patrat_c_4", corner_4, length, glm::vec3(1, 0, 0));
        AddMeshToList(patrat_c_4);

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
            VertexFormat(glm::vec3(7.5f, 0, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15.0f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 30.0f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 15.f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(0.0f, 0, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 0.5), glm::vec3(1, 0.38, 0), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(7.5f, 0, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15.0f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 30.0f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 15.f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(0.0f, 0, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 0), glm::vec3(0.612, 0, 1), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(7.5f, 0, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15.0f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 30.0f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 15.f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(0.0f, 0, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 0), glm::vec3(0, 0.33, 1), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(7.5f, 0, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 15.0f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(7.5f, 30.0f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 15.f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),

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
            VertexFormat(glm::vec3(0.0f, 0, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(0, 7.5f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 7.5f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),
            VertexFormat(glm::vec3(15.0f, 0.0f, 0), glm::vec3(1, 0.98, 0), glm::vec3(0.2, 0.8, 0.6)),

        };
        vector<unsigned int> indici11 =
        {
           0, 2, 3,
           0, 1, 2,
        };

        CreateMesh("dreptunghi_romb_4", vertecsi11, indici11);

        // desenare stea
        vector<VertexFormat> vertecsi12
        {
        // prima data punctele exterioare (de pe cerc)
        VertexFormat(glm::vec3(0.0 * 4, 2.00 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),     // C - 0
        VertexFormat(glm::vec3(-1.91 * 4, 0.6 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),   // G -  1
        VertexFormat(glm::vec3(-1.43 * 4, -1.4 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // D - 2
        VertexFormat(glm::vec3(1.4 * 4, -1.43 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),    // E - 3
        VertexFormat(glm::vec3(1.91 * 4, 0.6 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),    // F - 4
        // coordonatele interioare
        VertexFormat(glm::vec3(-0.59 * 4, 0.6 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // H - 5
        VertexFormat(glm::vec3(-0.86 * 4, 0.6 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // J - 6
        VertexFormat(glm::vec3(-0.02 * 4, -0.55 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // K - 7                                                                                          
        VertexFormat(glm::vec3(0.84 * 4, -0.04 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // L - 8                                                                                            
        VertexFormat(glm::vec3(0.57 * 4, 0.9 * 4, 0), glm::vec3(1, 0, 0.53), glm::vec3(0.2, 0.8, 0.6)),  // I - 9                                                                                            
        };
        vector<unsigned int> indici12 =
        {
           1, 7, 4,      // GKF
           0, 2, 7,      // CDK
           0, 7, 3       // CKE


        };

        CreateMesh("stea", vertecsi12, indici12);

        // creare hexagon dublu

        // pentru hexagonul mare
        vector<VertexFormat> vertecsi13
        {
        VertexFormat(glm::vec3(0 , 5.97 / 2  , 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),     // C - 0
        VertexFormat(glm::vec3(-5.29 / 2, 2.78 / 2 , 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),   // D -  1
        VertexFormat(glm::vec3(-5.18 / 2, -2.98 / 2, 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),  // E - 2
        VertexFormat(glm::vec3(0, -5.97 / 2 , 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),    // F - 3
        VertexFormat(glm::vec3(5.18 / 2 , -2.98 / 2 , 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),    // B - 4
        VertexFormat(glm::vec3(5.28 / 2 , 2.8 / 2 , 2), glm::vec3(0, 0.094, 1), glm::vec3(0.2, 0.8, 0.6)),    // G - 5
        VertexFormat(glm::vec3(0.0, 0.0, 2), glm::vec3(1, 1, 1), glm::vec3(0.2, 0.8, 0.6)),    // A - 6
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

        Mesh* mesh_hexagon = new Mesh("hexagon_mare");
        mesh_hexagon->InitFromData(vertecsi13, indici13);
        meshes[mesh_hexagon->GetMeshID()] = mesh_hexagon;
        //CreateMesh("hexagon_mare", vertecsi13, indici13);



        vector<VertexFormat> vertecsi14
        {
        // pentru hexagonul mic din interior 
        VertexFormat(glm::vec3(0, 4, 2), glm::vec3(0, 0.652, 1), glm::vec3(0.2, 0.8, 0.6)),       // H - 7 0
        VertexFormat(glm::vec3(-3.57, 2.03, 2), glm::vec3(0, 0.652, 1), glm::vec3(0.2, 0.8, 0.6)),   // I -  8 1
        VertexFormat(glm::vec3(-3.57, -1.95, 2), glm::vec3(0, 0.652, 1), glm::vec3(0.2, 0.8, 0.6)),  // J - 9 2
        VertexFormat(glm::vec3(0, -4, 2), glm::vec3(0, 0.652 , 1), glm::vec3(0.2, 0.8, 0.6)),      // K - 10 3
        VertexFormat(glm::vec3(3.54, -2.03, 2), glm::vec3(0, 0.652, 1), glm::vec3(0.2, 0.8, 0.6)),   // M - 11 4
        VertexFormat(glm::vec3(3.5, 2.03, 2), glm::vec3(0, 0.652, 1), glm::vec3(0.2, 0.8, 0.6)),    // L - 12 5
        VertexFormat(glm::vec3(0.0, 0.0, 2), glm::vec3(1, 1, 1), glm::vec3(0.2, 0.8, 0.6)),    // A - 6
        
        };

        vector<unsigned int> indici14 =
        {
            // pentru hexagonul mare
            6, 0, 1,    // AHI
            6, 1, 2,    // AIJ
            6, 2, 3,    // AJK
            6, 3, 4,    // AKM
            6, 4, 5,    // AML
            6, 5, 0,    // ALH
           
           

              


        };

        //CreateMesh("hexagon_mic", vertecsi14, indici14);

        Mesh* mesh_hexagon_mic = new Mesh("hexagon_mic");
        mesh_hexagon_mic->InitFromData(vertecsi14, indici14);
        meshes[mesh_hexagon_mic->GetMeshID()] = mesh_hexagon_mic;

        // desenare proiectil (stea mai mare)
         // desenare stea
        vector<VertexFormat> vertecsi15
        {
            // prima data punctele exterioare (de pe cerc)
            VertexFormat(glm::vec3(0.0 * 2, 2.00 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),     // C - 0
            VertexFormat(glm::vec3(-1.91 * 2, 0.6 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),   // G -  1
            VertexFormat(glm::vec3(-1.43 * 2, -1.4 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // D - 2
            VertexFormat(glm::vec3(1.4 * 2, -1.43 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),    // E - 3
            VertexFormat(glm::vec3(1.91 * 2, 0.6 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),    // F - 4
            // coordonatele interioare
            VertexFormat(glm::vec3(-0.59 * 2, 0.6 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // H - 5
            VertexFormat(glm::vec3(-0.86 * 2, 0.6 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // J - 6
            VertexFormat(glm::vec3(-0.02 * 2, -0.55 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // K - 7                                                                                          
            VertexFormat(glm::vec3(0.84 * 2, -0.04 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // L - 8                                                                                            
            VertexFormat(glm::vec3(0.57 * 2, 0.9 * 2, 0), glm::vec3(1, 0, 0.98), glm::vec3(0.2, 0.8, 0.6)),  // I - 9                                                                                            
        };
        vector<unsigned int> indici15 =
        {
           1, 7, 4,      // GKF
           0, 2, 7,      // CDK
           0, 7, 3       // CKE


        };

        CreateMesh("proiectil", vertecsi15, indici15);


        














        






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


    // desenare dreptunghi
    RenderMesh(meshes["dreptunghi"], shaders["VertexColor"], glm::vec3(-50.0f, -25.0f, 0), glm::vec3(0.25f));

    // desenare patrate
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-42.0f, -25.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-30.0f, -25.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-18.0f, -25.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-42.0f, -13.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-30.0f, -13.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-18.0f, -13.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-42.0f, -1.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-30.0f, -1.0f, 1), glm::vec3(0.25f));
    RenderMesh(meshes["patrat"], shaders["VertexColor"], glm::vec3(-18.0f, -1.0f, 1), glm::vec3(0.25f));

    // desenare patrate fara contur
    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["patrat_c_1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["patrat_c_2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["patrat_c_3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["patrat_c_4"], shaders["VertexColor"], modelMatrix);


    // desenare patrate mai mici pentru bonus
    RenderMesh(meshes["patrat_viata"], shaders["VertexColor"], glm::vec3(14.0f, 20.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["patrat_viata"], shaders["VertexColor"], glm::vec3(24.0f, 20.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["patrat_viata"], shaders["VertexColor"], glm::vec3(34.0f, 20.0f, 0), glm::vec3(0.25f));

    // desenare proiectile
    RenderMesh(meshes["romb_1"], shaders["VertexColor"], glm::vec3(-41.0f, 19.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["dreptunghi_romb_1"], shaders["VertexColor"], glm::vec3(-39.0f, 22.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["romb_2"], shaders["VertexColor"], glm::vec3(-27.0f, 19.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["dreptunghi_romb_2"], shaders["VertexColor"], glm::vec3(-25.0f, 22.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["romb_3"], shaders["VertexColor"], glm::vec3(-13.0f, 19.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["dreptunghi_romb_3"], shaders["VertexColor"], glm::vec3(-11.0f, 22.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["romb_4"], shaders["VertexColor"], glm::vec3(1.0f, 19.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["dreptunghi_romb_4"], shaders["VertexColor"], glm::vec3(3.0f, 22.0f, 0), glm::vec3(0.25f));

    // desenare stele
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(-42.0f, 16.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(-28.0f, 16.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(-24.0f, 16.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(-14.0f, 16.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(-10.0f, 16.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(0.0f, 16.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(4.0f, 16.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(8.0f, 16.0f, 0), glm::vec3(0.25f));

    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(14.0f, 18.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(18.0f, 18.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(22.0f, 18.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(26.0f, 18.0f, 0), glm::vec3(0.25f));
    RenderMesh(meshes["stea"], shaders["VertexColor"], glm::vec3(30.0f, 18.0f, 0), glm::vec3(0.25f));

    //RenderMesh(meshes["hexagon_mare"], shaders["VertexColor"], glm::vec3(0.0f, 0.0f, 1), glm::vec3(0.25f));
    //RenderMesh(meshes["hexagon_mic"], shaders["VertexColor"], glm::vec3(0.0f, 0.0f, 1.1f), glm::vec3(0.25f));
    
    
    /*
    * translatie inamic din partea dreapta a scenei, 
      dispare la linia rosie,
      are coordonate pentru patratele din mijloc
    */ 
    translate_hexagon_X += deltaTimeSeconds * -5.0f;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(50, -8.0f);
    if (translate_hexagon_X > -91.0f) {
        modelMatrix *= transform2D::Translate(translate_hexagon_X, 0.0f);
        RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);
        
    }
    
    // translatie + rotatie proiectil (ulterior va fi utila cand voi aseza proiectile
    // la iesirea din romb atunci cand sunt inamici pe linie)
        
    modelMatrix = glm::mat3(1);
    translate_stea_X += deltaTimeSeconds * 10.0f;
    modelMatrix *= transform2D::Translate(10, 4);
    modelMatrix *= transform2D::Translate(translate_stea_X, 0.0f);
    radiani -= deltaTimeSeconds * 3;
    modelMatrix *= transform2D::Rotate(radiani);
    RenderMesh2D(meshes["proiectil"], shaders["VertexColor"], modelMatrix);

    // scalare pentru disparitie romb (va fi utila in doua cazuri ce vor urma mai tarziu)
    // scalare pana la (0, 0) efect de disparitie
    modelMatrix = glm::mat3(1);
    

    if (scaleX >= 0.0) {
        scaleX += deltaTimeSeconds * -0.2;
        //mentine forma de patrat
        scaleY = scaleX;
        modelMatrix *= transform2D::Scale(scaleX, scaleY);
        RenderMesh2D(meshes["romb_1"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["dreptunghi_romb_1"], shaders["VertexColor"], modelMatrix);
    }

    //RenderMesh(meshes["romb_1"], shaders["VertexColor"], glm::vec3(-1.0f, -25.0f, 0), glm::vec3(0.25f));
    //RenderMesh(meshes["dreptunghi_romb_1"], shaders["VertexColor"], glm::vec3(1.0f, -22.0f, 0), glm::vec3(0.25f));

    if (scaleX >= 0.0) {
        scaleX += deltaTimeSeconds * -0.2;
        //mentine forma de patrat
        scaleY = scaleX;
        modelMatrix *= transform2D::Scale(scaleX, scaleY);
        RenderMesh2D(meshes["hexagon_mare"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["hexagon_mic"], shaders["VertexColor"], modelMatrix);
    }

   
    






   


   

   

}

void TEMA1::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    // TODO(student): Create the VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    unsigned int VBO = 0;
    // TODO(student): Create the VBO and bind it
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);


    // TODO(student): Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO = 0;
    // TODO(student): Create the IBO and bind it
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // TODO(student): Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // ========================================================================
    // This section demonstrates how the GPU vertex shader program
    // receives data. It will be learned later, when GLSL shaders will be
    // introduced. For the moment, just think that each property value from
    // our vertex format needs to be sent to a certain channel, in order to
    // know how to receive it in the GLSL vertex shader.

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // TODO(student): Unbind the VAO
    glBindVertexArray(0);

    // Check for OpenGL errors
    if (GetOpenGLError() == GL_INVALID_OPERATION)
    {
        cout << "\t[NOTE] : For students : DON'T PANIC! This error should go away when completing the tasks." << std::endl;
        cout << "\t[NOTE] : For developers : This happens because OpenGL core spec >=3.1 forbids null VAOs." << std::endl;
    }

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
}



void TEMA1::FrameEnd()
{
    
}


void TEMA1::DrawScene(glm::mat3 visMatrix)
{
   
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


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
}


void TEMA1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void TEMA1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void TEMA1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


