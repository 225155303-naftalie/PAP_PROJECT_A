#ifndef ASSETS_H
#define ASSETS_H

#define MAX 100

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
int  findAssetByID(int id);

extern int    assetIDs[MAX];
extern char   assetNames[MAX][50];
extern char   assetTypes[MAX][30];
extern double assetValues[MAX];
extern char   assetDepts[MAX][50];
extern char   assetConditions[MAX][20];
extern int    assetCount;

#endif