#pragma once

class MpmSimulator: public MPxLocatorNode
{
public:
	enum InitType
	{
		INIT_FROM_VDB = 0,
		INIT_SPHERE	  = 1,
		INIT_TWO_SPHERES=2,
		INIT_EMPTY = 3,
	};
	enum DisplayType
	{
		DISP_THIS_FRAME = 0,
		DISP_LAST_FRAME = 1
	};
	enum RasterizeType
	{
		RASTERIZE_SPHERE = 0,
		RASTERIZE_TRAIL = 1,
	};

	MpmSimulator(void);
	~MpmSimulator(void);
	void				postConstructor();

	virtual void		draw( M3dView & view, const MDagPath & path, M3dView::DisplayStyle style, M3dView:: DisplayStatus );
	virtual bool		isBounded() const{return true;}
	virtual MBoundingBox boundingBox() const;

	virtual MStatus		compute( const MPlug& plug, MDataBlock& data );
	static  void*		creator();
	static  MStatus		initialize();

	static MTypeId		m_id;
	static const char*  m_nodeName;

	bool				initSolver();
	bool				stepSolver();
	int					getNumSampledParticle();

	bool				saveCurStatus(const char* customName = NULL);
	bool				loadCurStatus(const char* fileName, bool isAppend);

private:
	void				drawIcon();
	void				drawCell();
	int					getCurFrame();
	bool				initParticle(int ithFrame);
	MStatus				computeVDB(openvdb::FloatGrid::Ptr& ls, float voxelSize, float halfWidth, float volumeFactor);
	bool				updateCollider(int ithFrame);
	void				drawSdf( int frame, bool showCurrent = true, bool showPrev = false, bool showCurrentVel = true, bool showPrevVel = false );
	MBoundingBox		m_box;
	MpmCore				m_core;

	static MObject		s_boxMin;			// 
	static MObject		s_boxMax;
	static MObject		s_cellSize;
	static MObject		s_nParticlePerCell;
	static MObject		s_boundary;

	// physical param
	static MObject		s_particleDensity;
	static MObject		s_youngs;
	static MObject		s_poisson;
	static MObject		s_hardening;
	static MObject		s_criticalCompression;
	static MObject		s_criticalStretch;
	static MObject		s_friction;
	static MObject		s_flip;
	static MObject		s_gravity;
	static MObject		s_deltaT;
	static MObject		s_nSubStep;

	// input particle
	static MObject		s_initParticle;
	static MObject		s_initType;
	static MObject		s_initTrans0;
	static MObject		s_initTrans1;
	static MObject		s_initDeltaTime;

	// particle
	static MObject		s_particleStr;
	static MObject		s_inputParticle;
	static MObject		s_outputParticle;
	static MObject		s_sampleRate;
	static MObject		s_numSampledParticle;
	static MObject		s_outputVDB;
	static MObject		s_vdbVoxelSize;
	static MObject		s_vdbHalfWidth;
	static MObject		s_vdbVolumeFactor;
	static MObject		s_vdbVelocityFactor;
	static MObject		s_vdbVelocitySampleDistance;
	static MObject		s_vdbType;
	static MObject		s_vdbRmin;
	static MObject		s_vdbRmax;
	static MObject		s_time;
	static MObject		s_immediateUpdate;

	// loading and saving
	static MObject		s_saveEveryFrame;
	static MObject		s_saveFilePath;
	static MObject		s_saveFilePrefix;

	// collision
	static MObject		s_colliderVdb;
	static MObject		s_colliderTrans;

	// display
	static MObject		s_displayType;
	static MObject		s_displaySdf;
	static MObject		s_displaySdfVel;
	static MObject		s_displayGrid;

	static const char*  s_boxMinName[2];
	static const char*	s_boxMaxName[2];
	static const char*  s_cellSizeName[2];
	static const char*	s_nParticlePerCellName[2];
	static const char*  s_boundaryName[2];

	static const char*  s_particleDensityName[2];
	static const char*	s_youngsName[2];
	static const char*	s_poissonName[2];
	static const char*	s_hardeningName[2];
	static const char*	s_criticalCompressionName[2];
	static const char*	s_criticalStretchName[2];
	static const char*	s_frictionName[2];
	static const char*	s_flipName[2];
	static const char*	s_gravityName[2];
	static const char*	s_deltaTName[2];
	static const char*  s_nSubStepName[2];

	static const char*	s_initParticleName[2];
	static const char*	s_initTypeName[2];
	static const char*	s_initTrans0Name[2];
	static const char*  s_initTrans1Name[2];
	static const char*  s_initDeltaTimeName[2];

	static const char*  s_particleStrName[2];
	static const char*  s_inputParticleName[2];
	static const char*  s_outputParticleName[2];
	static const char*  s_sampleRateName[2];
	static const char*  s_numSampledParticleName[2];
	static const char*  s_outputVDBName[2];
	static const char*	s_vdbVoxelSizeName[2];
	static const char*	s_vdbHalfWidthName[2];
	static const char*	s_vdbVolumeFactorName[2];
	static const char*  s_vdbVelocityFactorName[2];
	static const char*  s_vdbVelocitySampleDistanceName[2];
	static const char*  s_vdbTypeName[2];
	static const char*  s_vdbRminName[2];
	static const char*	s_vdbRmaxName[2];
	static const char*	s_timeName[2];
	static const char*  s_immediateUpdateName[2];
	static const char*  s_saveEveryFrameName[2];
	static const char*  s_saveFilePathName[2];
	static const char*  s_saveFilePrefixName[2];
	static const char*  s_colliderVdbName[2];
	static const char*  s_colliderTransName[2];
	static const char*  s_displayTypeName[2];
	static const char*  s_displaySdfName[2];
	static const char*  s_displaySdfVelName[2];
	static const char*  s_displayGridName[2];
};

