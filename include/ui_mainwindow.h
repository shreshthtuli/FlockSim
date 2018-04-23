/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <flock.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    Flock *glwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Location;
    QHBoxLayout *horizontalLayout;
    QLabel *x;
    QSlider *xloc;
    QLabel *xlabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *y;
    QSlider *yloc;
    QLabel *ylabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *z;
    QSlider *zloc;
    QLabel *zlabel;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Strength;
    QSlider *strength;
    QLabel *strengthlabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Adventorous;
    QSlider *adventorous;
    QLabel *advlabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Signtedness;
    QSlider *sightedness;
    QLabel *sightlabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Fov;
    QSpinBox *fova;
    QLabel *fovlabel;
    QSpinBox *fovb;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *avgspeed;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *maxspeed;
    QLabel *label_13;
    QLabel *label_21;
    QLabel *avgacc;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *maxacc;
    QLabel *label_26;
    QLabel *label_2;
    QLabel *avgpow;
    QLabel *label_15;
    QLabel *label_4;
    QLabel *maxpow;
    QLabel *label_16;
    QLabel *label_6;
    QLabel *totenergy;
    QLabel *label_17;
    QLabel *label_8;
    QLabel *maxenergy;
    QLabel *label_18;
    QLabel *label_10;
    QLabel *avgmass;
    QLabel *label_19;
    QLabel *label_12;
    QLabel *maxmass;
    QLabel *label_20;
    QLabel *label_14;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QCheckBox *sep;
    QCheckBox *align;
    QCheckBox *coh;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *AddBoid;
    QPushButton *reset_timer;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        glwidget = new Flock(centralWidget);
        glwidget->setObjectName(QStringLiteral("glwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glwidget->sizePolicy().hasHeightForWidth());
        glwidget->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(glwidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Location = new QLabel(centralWidget);
        Location->setObjectName(QStringLiteral("Location"));

        verticalLayout->addWidget(Location);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        x = new QLabel(centralWidget);
        x->setObjectName(QStringLiteral("x"));

        horizontalLayout->addWidget(x);

        xloc = new QSlider(centralWidget);
        xloc->setObjectName(QStringLiteral("xloc"));
        xloc->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(xloc);

        xlabel = new QLabel(centralWidget);
        xlabel->setObjectName(QStringLiteral("xlabel"));

        horizontalLayout->addWidget(xlabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        y = new QLabel(centralWidget);
        y->setObjectName(QStringLiteral("y"));

        horizontalLayout_2->addWidget(y);

        yloc = new QSlider(centralWidget);
        yloc->setObjectName(QStringLiteral("yloc"));
        yloc->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(yloc);

        ylabel = new QLabel(centralWidget);
        ylabel->setObjectName(QStringLiteral("ylabel"));

        horizontalLayout_2->addWidget(ylabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        z = new QLabel(centralWidget);
        z->setObjectName(QStringLiteral("z"));

        horizontalLayout_3->addWidget(z);

        zloc = new QSlider(centralWidget);
        zloc->setObjectName(QStringLiteral("zloc"));
        zloc->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(zloc);

        zlabel = new QLabel(centralWidget);
        zlabel->setObjectName(QStringLiteral("zlabel"));

        horizontalLayout_3->addWidget(zlabel);


        verticalLayout->addLayout(horizontalLayout_3);

        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Strength = new QLabel(centralWidget);
        Strength->setObjectName(QStringLiteral("Strength"));

        horizontalLayout_4->addWidget(Strength);

        strength = new QSlider(centralWidget);
        strength->setObjectName(QStringLiteral("strength"));
        strength->setMaximum(100);
        strength->setValue(100);
        strength->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(strength);

        strengthlabel = new QLabel(centralWidget);
        strengthlabel->setObjectName(QStringLiteral("strengthlabel"));

        horizontalLayout_4->addWidget(strengthlabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Adventorous = new QLabel(centralWidget);
        Adventorous->setObjectName(QStringLiteral("Adventorous"));

        horizontalLayout_5->addWidget(Adventorous);

        adventorous = new QSlider(centralWidget);
        adventorous->setObjectName(QStringLiteral("adventorous"));
        adventorous->setMaximum(1000);
        adventorous->setValue(50);
        adventorous->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(adventorous);

        advlabel = new QLabel(centralWidget);
        advlabel->setObjectName(QStringLiteral("advlabel"));

        horizontalLayout_5->addWidget(advlabel);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        Signtedness = new QLabel(centralWidget);
        Signtedness->setObjectName(QStringLiteral("Signtedness"));

        horizontalLayout_6->addWidget(Signtedness);

        sightedness = new QSlider(centralWidget);
        sightedness->setObjectName(QStringLiteral("sightedness"));
        sightedness->setMaximum(100);
        sightedness->setValue(10);
        sightedness->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sightedness);

        sightlabel = new QLabel(centralWidget);
        sightlabel->setObjectName(QStringLiteral("sightlabel"));

        horizontalLayout_6->addWidget(sightlabel);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Fov = new QLabel(centralWidget);
        Fov->setObjectName(QStringLiteral("Fov"));

        horizontalLayout_7->addWidget(Fov);

        fova = new QSpinBox(centralWidget);
        fova->setObjectName(QStringLiteral("fova"));
        fova->setValue(4);

        horizontalLayout_7->addWidget(fova);

        fovlabel = new QLabel(centralWidget);
        fovlabel->setObjectName(QStringLiteral("fovlabel"));

        horizontalLayout_7->addWidget(fovlabel);

        fovb = new QSpinBox(centralWidget);
        fovb->setObjectName(QStringLiteral("fovb"));
        fovb->setValue(3);

        horizontalLayout_7->addWidget(fovb);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        verticalLayout_2->addLayout(horizontalLayout_9);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        avgspeed = new QLabel(centralWidget);
        avgspeed->setObjectName(QStringLiteral("avgspeed"));

        gridLayout->addWidget(avgspeed, 0, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        maxspeed = new QLabel(centralWidget);
        maxspeed->setObjectName(QStringLiteral("maxspeed"));

        gridLayout->addWidget(maxspeed, 1, 1, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 2, 1, 1);

        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 2, 0, 1, 1);

        avgacc = new QLabel(centralWidget);
        avgacc->setObjectName(QStringLiteral("avgacc"));

        gridLayout->addWidget(avgacc, 2, 1, 1, 1);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 2, 2, 1, 1);

        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 3, 0, 1, 1);

        maxacc = new QLabel(centralWidget);
        maxacc->setObjectName(QStringLiteral("maxacc"));

        gridLayout->addWidget(maxacc, 3, 1, 1, 1);

        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout->addWidget(label_26, 3, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        avgpow = new QLabel(centralWidget);
        avgpow->setObjectName(QStringLiteral("avgpow"));

        gridLayout->addWidget(avgpow, 4, 1, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 4, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        maxpow = new QLabel(centralWidget);
        maxpow->setObjectName(QStringLiteral("maxpow"));

        gridLayout->addWidget(maxpow, 5, 1, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 5, 2, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        totenergy = new QLabel(centralWidget);
        totenergy->setObjectName(QStringLiteral("totenergy"));

        gridLayout->addWidget(totenergy, 6, 1, 1, 1);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 6, 2, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        maxenergy = new QLabel(centralWidget);
        maxenergy->setObjectName(QStringLiteral("maxenergy"));

        gridLayout->addWidget(maxenergy, 7, 1, 1, 1);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 7, 2, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        avgmass = new QLabel(centralWidget);
        avgmass->setObjectName(QStringLiteral("avgmass"));

        gridLayout->addWidget(avgmass, 8, 1, 1, 1);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 8, 2, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 9, 0, 1, 1);

        maxmass = new QLabel(centralWidget);
        maxmass->setObjectName(QStringLiteral("maxmass"));

        gridLayout->addWidget(maxmass, 9, 1, 1, 1);

        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 9, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_3->addWidget(label_14);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout_2->addWidget(checkBox_2);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        sep = new QCheckBox(centralWidget);
        sep->setObjectName(QStringLiteral("sep"));
        sep->setChecked(true);

        verticalLayout_2->addWidget(sep);

        align = new QCheckBox(centralWidget);
        align->setObjectName(QStringLiteral("align"));
        align->setChecked(true);

        verticalLayout_2->addWidget(align);

        coh = new QCheckBox(centralWidget);
        coh->setObjectName(QStringLiteral("coh"));
        coh->setChecked(true);

        verticalLayout_2->addWidget(coh);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(400);

        verticalLayout_2->addWidget(spinBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        AddBoid = new QPushButton(centralWidget);
        AddBoid->setObjectName(QStringLiteral("AddBoid"));

        verticalLayout_2->addWidget(AddBoid);

        reset_timer = new QPushButton(centralWidget);
        reset_timer->setObjectName(QStringLiteral("reset_timer"));

        verticalLayout_2->addWidget(reset_timer);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout_2->addWidget(progressBar);


        horizontalLayout_8->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(strength, SIGNAL(valueChanged(int)), strengthlabel, SLOT(setNum(int)));
        QObject::connect(sightedness, SIGNAL(valueChanged(int)), sightlabel, SLOT(setNum(int)));
        QObject::connect(adventorous, SIGNAL(valueChanged(int)), advlabel, SLOT(setNum(int)));
        QObject::connect(xloc, SIGNAL(valueChanged(int)), xlabel, SLOT(setNum(int)));
        QObject::connect(zloc, SIGNAL(valueChanged(int)), zlabel, SLOT(setNum(int)));
        QObject::connect(yloc, SIGNAL(valueChanged(int)), ylabel, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Location->setText(QApplication::translate("MainWindow", "Location:", Q_NULLPTR));
        x->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        xlabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        y->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        ylabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        z->setText(QApplication::translate("MainWindow", "z:", Q_NULLPTR));
        zlabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "Random location", Q_NULLPTR));
        Strength->setText(QApplication::translate("MainWindow", "Strength:", Q_NULLPTR));
        strengthlabel->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        Adventorous->setText(QApplication::translate("MainWindow", "Adventorous:", Q_NULLPTR));
        advlabel->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        Signtedness->setText(QApplication::translate("MainWindow", "Sightedness:", Q_NULLPTR));
        sightlabel->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        Fov->setText(QApplication::translate("MainWindow", "Field of view:", Q_NULLPTR));
        fovlabel->setText(QApplication::translate("MainWindow", "* PI/", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Avergae speed:", Q_NULLPTR));
        avgspeed->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "m/s", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Maximum speed:", Q_NULLPTR));
        maxspeed->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "m/s", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Average acceleration:", Q_NULLPTR));
        avgacc->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "m/s^2", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Maximum acceleration", Q_NULLPTR));
        maxacc->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "m/s^2", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Average power:", Q_NULLPTR));
        avgpow->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Maximum power:", Q_NULLPTR));
        maxpow->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "W", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Total Energy:", Q_NULLPTR));
        totenergy->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "J", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Maximum Energy:", Q_NULLPTR));
        maxenergy->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "J", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Average mass of cereal:", Q_NULLPTR));
        avgmass->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "g", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Maximum mass:", Q_NULLPTR));
        maxmass->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "g", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "where the average mass of the bird is 80g.", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Colour", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Random calculation", Q_NULLPTR));
        sep->setText(QApplication::translate("MainWindow", "Separation", Q_NULLPTR));
        align->setText(QApplication::translate("MainWindow", "Alignment", Q_NULLPTR));
        coh->setText(QApplication::translate("MainWindow", "Cohesion", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Auto Add Boids", Q_NULLPTR));
        AddBoid->setText(QApplication::translate("MainWindow", "Add Boid", Q_NULLPTR));
        reset_timer->setText(QApplication::translate("MainWindow", "Reset timer", Q_NULLPTR));
        progressBar->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
