#ifndef QDIRECTORY_H
#define QDIRECTORY_H

#include <QDir>
#include <QFile>

class QDirectory{

public:
    QDirectory();
    ~QDirectory();

    void loadFile();
    const QMap<QString, QDateTime>& map() const;

private:
    QString _path;
    QMap<QString, QDateTime> _map;


};

#endif // QDIRECTORY_H
