#ifndef JSDES_H
#define JSDES_H
#include <QFile>
#include <QTextStream>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueList>

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
class JSDES
{
public:
    JSDES();
    void readJs();
    QString DES_encode(QString data, QString key);
    QString DES_decode(QString data, QString key);
private:
    QScriptEngine engine;
    QScriptValue js;        //个人理解：加载js文本到操作引擎
};

#endif // JSDES_H
