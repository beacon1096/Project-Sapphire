#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QAction>
#include <QMap>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>
#include "BeaconFileIO.h"
#include "BeaconCodeProperty.h"
#include "BeaconExternalProgram.h"
#include "BeaconCompilerBackend.h"
#include "BeaconAboutInterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int newFileCnt;
private:
    Ui::MainWindow *ui;
private:
    //T
    BeaconCompilerBackend *compiler = nullptr;
    QsciScintilla *editor = nullptr;
    QsciLexerCPP *textLexer = nullptr;
    BeaconExternalProgram *instance = nullptr;
//QMenu
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuBuild;
    QMenu *menuDebug;
    QMenu *menuLanguage;
    QMenu *menuHelp;
    QMenu *menuTest;
//QAction-File
    QAction *actionFileNew;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFileSaveAs;
    QAction *actionFileCloseFile;
    QAction *actionFileCloseAll;
    QAction *actionFileCloseOthers;
    QAction *actionFileRecentFiles;
    QAction *actionExit;
//QAction-Edit
    QAction *actionEditUndo;
    QAction *actionEditRedo;
    QAction *actionEditSelectAll;
    QAction *actionEditCopy;
    QAction *actionEditCut;
    QAction *actionEditPaste;
    QAction *actionEditSearch;
    QAction *actionEditReplace;
    QAction *actionEditNext;
    QAction *actionEditPrevious;
    QAction *actionEditGoTo;
    QAction *actionEditGoToBrace;
    QAction *actionEditSettings;
//QActions-View
    QAction *actionViewFileBrowser;
    QAction *actionViewMessage;
//QActions-Build
    QAction *actionBuildCompile;
    QAction *actionBuildStopCompile;
    QAction *actionBuildExecute;
    QAction *actionBuildStopExecute;    
//QActions-Debug
    QAction *actionDebugStart;
    QAction *actionDebugStop;
    QAction *actionDebugPause;
    QAction *actionDebugStepOver;
    QAction *actionDebugStepInto;
    QAction *actionDebugStepOut;
    QAction *actionDebugRunToCursor;
    QAction *actionDebugToggleBreakpoint;
//QActions-Language
    QAction *actionLanguageChinese;
    QAction *actionLanguageEnglish;
//QActions-Help
    QAction *actionHelpHelp;
    QAction *actionHelpAboutProgram;
    QAction *actionHelpAboutFramework;
    QAction *actionHelpAboutQt;
//QActions-ProgramDebug
    QAction *actionBCPDExternalProgram;
//QTextBrowser
    QsciScintilla *currentEditor;
//QList-Opened Files && editorList
    QVector<BeaconCodeProperty> fileList;
    QMap<QString,QsciScintilla*> editorList;
//About Interface
    BeaconAboutInterface *abI;
public slots:
//Statement updates
    void tabChanged(int target);
    void codeChanged();
//QActions-File
    void triggeredNew();
    void triggeredNew(QString fileName);
    void triggeredOpen();
    void triggeredSave();
    void triggeredSaveAs();
    void triggeredExit();
//QActions-Edit
    void triggeredRedo();
    void triggeredUndo();
    void triggeredSelectAll();
    void triggeredCopy();
    void triggeredCut();
    void triggeredPaste();
//QAciton-Build
    void triggeredBuild();
    void triggeredStopBuild();
    void triggeredExecute();
    void triggeredStopExecute();
//QActions-Help
    void showAboutQt();
    void showAboutBF();
    void showAboutProgram();
//QActions-Test
    void executeExternalProgram();
//Alternate Helpers
    void onInstanceExited();

private slots:
};


#endif // MAINWINDOW_H
