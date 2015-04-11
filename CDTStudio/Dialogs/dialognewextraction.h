#ifndef DIALOGNEWEXTRACTION_H
#define DIALOGNEWEXTRACTION_H

#include <QDialog>

namespace Ui {
class DialogNewExtraction;
}
class CDTFileSystem;

class DialogNewExtraction : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewExtraction(
            const QString &inputImage,
            CDTFileSystem* fileSys ,
            QWidget *parent = 0
    );
    ~DialogNewExtraction();

    QString name()          const;
    QColor  color()         const;
    QColor  borderColor()   const;
    double  opacity()       const;
    QString fileID()        const;

private slots:
    void onAccepted();

private:
    Ui::DialogNewExtraction *ui;
    QString inputImagePath;
    CDTFileSystem *fileSystem;

    QString shapefileTempPath;
    QString shapefileID;
};

#endif // DIALOGNEWEXTRACTION_H