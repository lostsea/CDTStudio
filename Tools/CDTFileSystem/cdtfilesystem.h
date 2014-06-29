#ifndef CDTFILESYSTEM_H
#define CDTFILESYSTEM_H

#include "cdtfilesystem_global.h"
#include <QtCore>
#include "log4qt/logger.h"

class CDTFileSystemPrivate;

class CDTFILESYSTEM_EXPORT CDTFileSystem:public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    CDTFileSystem(QObject* parent = NULL);
    ~CDTFileSystem();

    friend QDataStream CDTFILESYSTEM_EXPORT &operator<<(QDataStream &out, const CDTFileSystem &files);
    friend QDataStream CDTFILESYSTEM_EXPORT &operator>>(QDataStream &in, CDTFileSystem &files);

    bool registerFile(QString id,
            const QString &filePath,
            QString prefix = QString(),
            QString suffix = QString(),
            QStringList affiliatedFiles = QStringList());

    bool getFile(QString id,QString& filePath);
    bool getFile(QString id,QString& filePath,QStringList &affiliatedFiles);

    static bool GDALGetRasterVSIZipFile(const QString &srcPath,const QString &zipPath,bool deleteSrcFile);
    static bool GDALGetShapefileVSIZipFile(const QString &srcPath,const QString &zipPath,bool deleteSrcFile);
    static QStringList GetShapefileAffaliated(const QString &srcPath);
private:
    CDTFileSystemPrivate* pData;
};

//QDataStream CDTFILESYSTEM_EXPORT &operator<<(QDataStream &out, const CDTFileSystem &files);
//QDataStream CDTFILESYSTEM_EXPORT &operator>>(QDataStream &in, CDTFileSystem &files);


#endif // CDTFILESYSTEM_H
