#include "stdafx.h"
#include "MpmSimulator.h"

const char* MpmSimulator::m_nodeName = "MpmSimulator";
MTypeId MpmSimulator::m_id(0x00108A60);


MObject MpmSimulator::s_boxMin;
MObject MpmSimulator::s_boxMax;
MObject	MpmSimulator::s_cellSize;
MObject MpmSimulator::s_nParticlePerCell;
MObject	MpmSimulator::s_boundary;

MObject	MpmSimulator::s_particleDensity;
MObject	MpmSimulator::s_youngs;
MObject	MpmSimulator::s_poisson;
MObject	MpmSimulator::s_hardening;
MObject	MpmSimulator::s_criticalCompression;
MObject	MpmSimulator::s_criticalStretch;
MObject	MpmSimulator::s_friction;
MObject	MpmSimulator::s_flip;
MObject	MpmSimulator::s_gravity;
MObject	MpmSimulator::s_deltaT;
MObject	MpmSimulator::s_nSubStep;
MObject MpmSimulator::s_initParticle;
MObject MpmSimulator::s_initType;

MObject MpmSimulator::s_initTrans0;
MObject MpmSimulator::s_initTrans1;
MObject MpmSimulator::s_initDeltaTime;
MObject MpmSimulator::s_outputParticle;
MObject MpmSimulator::s_inputParticle;
MObject MpmSimulator::s_sampleRate;
MObject MpmSimulator::s_particleStr;
MObject MpmSimulator::s_numSampledParticle;
MObject MpmSimulator::s_outputVDB;
MObject MpmSimulator::s_vdbHalfWidth;
MObject MpmSimulator::s_vdbVoxelSize;
MObject MpmSimulator::s_vdbVolumeFactor;
MObject MpmSimulator::s_vdbVelocityFactor;
MObject MpmSimulator::s_vdbVelocitySampleDistance;
MObject MpmSimulator::s_vdbType;
MObject	MpmSimulator::s_vdbRmin;
MObject	MpmSimulator::s_vdbRmax;
MObject MpmSimulator::s_time;
MObject MpmSimulator::s_immediateUpdate;
MObject MpmSimulator::s_saveFilePrefix;
MObject MpmSimulator::s_saveFilePath;
MObject MpmSimulator::s_saveEveryFrame;
MObject	MpmSimulator::s_colliderVdb;
MObject	MpmSimulator::s_colliderTrans;
MObject	MpmSimulator::s_displayType;
MObject	MpmSimulator::s_displaySdf;
MObject	MpmSimulator::s_displaySdfVel;
MObject	MpmSimulator::s_displayGrid;

const char* MpmSimulator::s_displayTypeName[2]={"displayType","disptype"};
const char* MpmSimulator::s_displaySdfName[2]={"displaySdf", "dispsdf"};
const char* MpmSimulator::s_displaySdfVelName[2]={"displaySdfVelocity", "dispsdfvel"};
const char* MpmSimulator::s_displayGridName[2]={"displayCell","dispcell"};
const char* MpmSimulator::s_colliderTransName[2]={"colliderTrans", "cldrtrans"};
const char* MpmSimulator::s_colliderVdbName[2]={"colliderVdb","cldrvdb"};
const char* MpmSimulator::s_saveEveryFrameName[2]={"saveEveryFrame","saveef"};
const char* MpmSimulator::s_saveFilePathName[2]={"saveFolder","savefdr"};
const char* MpmSimulator::s_saveFilePrefixName[2]={"saveFilePrefix","savefpfx"};
const char* MpmSimulator::s_vdbRminName[2]={"minParticleRadius", "minptclr"};
const char* MpmSimulator::s_vdbRmaxName[2]={"maxParticleRadius", "maxptclr"};
const char* MpmSimulator::s_immediateUpdateName[2]={"immediateUpdate", "imupdate"};
const char* MpmSimulator::s_timeName[2]={"time", "time"};
const char* MpmSimulator::s_vdbTypeName[2]={"vdbType", "vdbtp"};
const char* MpmSimulator::s_vdbVelocitySampleDistanceName[2]={"vdbVelocitySampleDist", "vdbvelspldst"};
const char* MpmSimulator::s_vdbVelocityFactorName[2]={"vdbVelocityFactor", "vdbvelftr"};
const char* MpmSimulator::s_vdbVolumeFactorName[2]={"vdbVolumeFactor", "vdbvftr"};
const char* MpmSimulator::s_vdbHalfWidthName[2]={"vdbHalfWidth","vdbhw"};
const char* MpmSimulator::s_vdbVoxelSizeName[2]={"vdbVoxelSize", "vdbvsize"};
const char* MpmSimulator::s_outputVDBName[2]={"outputVDB","outvdb"};
const char* MpmSimulator::s_numSampledParticleName[2]={"numSampledParticle","nsplptcl"};
const char* MpmSimulator::s_particleStrName[2]={"particleName","ptclname"};
const char* MpmSimulator::s_sampleRateName[2]={"particleSampleRate","psplrt"};
const char* MpmSimulator::s_outputParticleName[2]={"outputParticle", "outptcl"};
const char* MpmSimulator::s_inputParticleName[2]={"inputParticle", "inptcl"};

const char* MpmSimulator::s_boxMinName[2]={"boxMin","bMin"};
const char* MpmSimulator::s_boxMaxName[2]={"boxMax","bMax"};
const char* MpmSimulator::s_cellSizeName[2]={"cellSize","cSize"};
const char* MpmSimulator::s_nParticlePerCellName[2]={"particlePerCell", "ppc"};
const char* MpmSimulator::s_boundaryName[2]={"boundary","bnd"};

const char*	MpmSimulator::s_particleDensityName[2]={"particleDensity","pdensity"};
const char*	MpmSimulator::s_youngsName[2]={"youngsModulus","ym"};
const char*	MpmSimulator::s_poissonName[2]={"possionRatio","pr"};
const char*	MpmSimulator::s_hardeningName[2]={"hardeningFactor","hf"};
const char*	MpmSimulator::s_criticalCompressionName[2]={"criticalCompression","cc"};
const char*	MpmSimulator::s_criticalStretchName[2]={"criticalStretch","cs"};
const char*	MpmSimulator::s_frictionName[2]={"friction","fr"};
const char*	MpmSimulator::s_flipName[2]={"flipPercent","fp"};
const char*	MpmSimulator::s_gravityName[2]={"gravity","gr"};
const char*	MpmSimulator::s_deltaTName[2]={"deltaTime","dt"};
const char* MpmSimulator::s_nSubStepName[2]={"numberOfSubsteps","noss"};
const char* MpmSimulator::s_initParticleName[2]={"initParticle","iptl"};
const char* MpmSimulator::s_initTypeName[2]={"initType","intp"};

const char* MpmSimulator::s_initTrans0Name[2]={"initStartTransform", "initstr"};
const char* MpmSimulator::s_initTrans1Name[2]={"initEndTransform", "initetr"};
const char* MpmSimulator::s_initDeltaTimeName[2]={"initDeltaTime", "initdt"};

MpmSimulator::MpmSimulator(void)
{
	m_box = MBoundingBox(MPoint(-1.1,-0.5,-1.1), MPoint(4.1,0.5,1.1));
}


MpmSimulator::~MpmSimulator(void)
{
}

int MpmSimulator::getCurFrame()
{
	int curFrame = 1;
	MGlobal::executeCommand("currentTime -q", curFrame);
	return curFrame;
}

void MpmSimulator::draw( M3dView & view, const MDagPath & path, M3dView::DisplayStyle style, M3dView:: DisplayStatus )
{
	int ithFrame = getCurFrame();
	MPlug displayTypePlug = Global::getPlug(this, s_displayTypeName[0]);
	if (displayTypePlug.asShort() == DISP_LAST_FRAME)
	{
		ithFrame--;
	}

	view.beginGL();
	glPushAttrib(GL_CURRENT_BIT);

	drawIcon();

	// 保证在世界空间模拟，所以需要抵消自身矩阵
	MMatrix mat  = path.inclusiveMatrixInverse();
	double  matBuf[4][4];
	mat.get(matBuf);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixd(&matBuf[0][0]);
	{
		drawCell();

		MPlug sdfPlug = Global::getPlug(this, s_displaySdfName[0]);
		MPlug sdfVelPlug = Global::getPlug(this, s_displaySdfVelName[0]);
		if (sdfPlug.asBool())
			drawSdf(ithFrame, true, true, sdfVelPlug.asBool(), true);

		m_box = MBoundingBox(MPoint(-1.1,-0.5,-1.1), MPoint(4.1,0.5,1.1));

		const MpmStatus* status = m_core.getRecorder().getStatusPtr(ithFrame);
		if(status)
		{
			status->draw();
		}
		

		Vector3f minPnt, cellSize;
		Vector3i nCell;
		m_core.getGridConfig(minPnt, cellSize, nCell);
		Vector3f maxPnt = minPnt + cellSize.cwiseProduct(nCell.cast<float>());

		MPoint boxMin = MPoint(minPnt[0],minPnt[1],minPnt[2])*mat;
		MPoint boxMax = MPoint(maxPnt[0],maxPnt[1],maxPnt[2])*mat;
		m_box = MBoundingBox(MPoint(-1.1,-0.5,-1.1), MPoint(4.1,0.5,1.1));
		m_box.expand(boxMin);
		m_box.expand(boxMax);
	}

	glPopAttrib();

	view.endGL();
}

void MpmSimulator::postConstructor()
{
	MStatus s;
	MFnDependencyNode nodeFn(thisMObject(), &s);

	if (s)
	{
		nodeFn.setName( "MpmSimulatorShape#", &s);
	}
}


void MpmSimulator::drawSdf( int frame, bool showCurrent /*= true*/, bool showPrev /*= false*/, bool showCurrentVel /*= true*/, bool showPrevVel /*= false*/ )
{
	const MpmStatus* pS = m_core.getRecorder().getStatusPtr(frame);
	if(!pS)
		return;
	Vector3f grid_min, grid_size;
	Vector3i grid_division;
	m_core.getGridConfig(grid_min, grid_size, grid_division);
	const vector<MpmStatus::GridData>& gridData = pS->getGridData();
	if (gridData.size() <= 0)
	{
		return;
	}

	glPointSize(2.f);
	Vector3f offset0 = grid_size * 0.3;
	Vector3f offset1 = grid_size * 0.1;
	const MpmStatus::GridData* pCell = &gridData[0];
	for (int k = 0; k < grid_division[2]; ++k)
	{
		for (int j = 0; j < grid_division[1]; ++j)
		{
			for (int i = 0; i < grid_division[0]; ++i, ++pCell)
			{
				Vector3f cellOri = grid_min + grid_size.cwiseProduct(Vector3f(i,j,k));
				if (pCell->m_collisionSdf < 0)
				{
					Vector3f pos = cellOri + offset0;
					if (showCurrent)
					{
						float v = -pCell->m_collisionSdf;
						float alpha = (v > 1.f ? 1.f : v);
						glColor4f(255/255.f,201/255.f,14/255.f, alpha);
						glBegin(GL_POINTS);
						glVertex3f(pos[0], pos[1], pos[2]);
						glEnd();
					}
					if (showCurrentVel)
					{
						Vector3f end = pos + pCell->m_collisionVelocity * 1/24.0;
						glColor4f(255/255.f,201/255.f,14/255.f,255/255.f);
						glBegin(GL_LINES);
						glVertex3f(pos[0], pos[1], pos[2]);
						glVertex3f(end[0], end[1], end[2]);
						glEnd();
					}
				}
			}
		}
	}
}

void MpmSimulator::drawCell()
{
	Vector3f minPnt, cellSize;
	Vector3i nCell;
	m_core.getGridConfig(minPnt, cellSize, nCell);

	Vector3f maxPnt = minPnt + cellSize.cwiseProduct(nCell.cast<float>());

	glBegin(GL_LINE_LOOP);
	glVertex3f(minPnt[0],minPnt[1],minPnt[2]);
	glVertex3f(maxPnt[0],minPnt[1],minPnt[2]);
	glVertex3f(maxPnt[0],maxPnt[1],minPnt[2]);
	glVertex3f(minPnt[0],maxPnt[1],minPnt[2]);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(minPnt[0],minPnt[1],maxPnt[2]);
	glVertex3f(maxPnt[0],minPnt[1],maxPnt[2]);
	glVertex3f(maxPnt[0],maxPnt[1],maxPnt[2]);
	glVertex3f(minPnt[0],maxPnt[1],maxPnt[2]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(minPnt[0],minPnt[1],minPnt[2]);
	glVertex3f(minPnt[0],minPnt[1],maxPnt[2]);

	glVertex3f(maxPnt[0],minPnt[1],minPnt[2]);
	glVertex3f(maxPnt[0],minPnt[1],maxPnt[2]);

	glVertex3f(minPnt[0],maxPnt[1],minPnt[2]);
	glVertex3f(minPnt[0],maxPnt[1],maxPnt[2]);

	glVertex3f(maxPnt[0],maxPnt[1],minPnt[2]);
	glVertex3f(maxPnt[0],maxPnt[1],maxPnt[2]);
	glEnd();

	MPlug cellPlug = Global::getPlug(this, s_displayGridName[0]);
	if (cellPlug.asBool())
	{
		glBegin(GL_LINES);
		for (int i = 0; i < nCell[0]; ++i)
		{
			glVertex3f(minPnt[0]+i*cellSize[0], minPnt[1], minPnt[2]);
			glVertex3f(minPnt[0]+i*cellSize[0], minPnt[1], maxPnt[2]);
		}
		for (int i = 0; i < nCell[2]; ++i)
		{
			glVertex3f(minPnt[0], minPnt[1], minPnt[2]+i*cellSize[2]);
			glVertex3f(maxPnt[0], minPnt[1], minPnt[2]+i*cellSize[2]);
		}
		glEnd();
	}

}

void MpmSimulator::drawIcon()
{
	float p[][3] = {{0.5,0,-1},{0.8,0,1},{-1,0,1},{0.2,0,0.4}};

	glBegin(GL_LINE_LOOP);
	glVertex3fv(p[0]);
	glVertex3fv(p[1]);
	glVertex3fv(p[2]);
	glEnd();

	glBegin(GL_LINES);
	glVertex3fv(p[0]);
	glVertex3fv(p[3]);

	glVertex3fv(p[1]);
	glVertex3fv(p[3]);

	glVertex3fv(p[2]);
	glVertex3fv(p[3]); 
	glEnd();

	// draw "MPM"
	glBegin(GL_LINE_STRIP);
	glVertex3f(1,0,1);
	glVertex3f(1,0,0);
	glVertex3f(1.4,0,0.7);
	glVertex3f(1.8,0,0);
	glVertex3f(1.8,0,1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(2,0,0.5);
	glVertex3f(2.8,0,0.5);
	glVertex3f(2.8,0,0);
	glVertex3f(2,0,0);
	glVertex3f(2,0,1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(3,0,1);
	glVertex3f(3,0,0);
	glVertex3f(3.4,0,0.7);
	glVertex3f(3.8,0,0);
	glVertex3f(3.8,0,1);
	glEnd();
}
MBoundingBox MpmSimulator::boundingBox() const
{
	return m_box;
}

int  MpmSimulator::getNumSampledParticle()
{
	MPlug samplePlug= Global::getPlug(this, s_sampleRateName[0]);
	int curFrame = getCurFrame();
	MpmStatus status;
	bool res = m_core.getRecorder().getStatus(curFrame, status);
	if (!res || status.getParticleCount() <= 0)
		return 0;
	int sampleRate = samplePlug.asInt();
	int sampledNum = (status.getParticleCount()-1)/sampleRate+1;
	PRINT_F("total ptcl: %d sampled ptcl: %d", status.getParticleCount(), sampledNum);
	return sampledNum;
}


class MyParticleList
{
protected:
	struct MyParticle {
		openvdb::Vec3R p, v;
		openvdb::Real  r;
	};
	openvdb::Real           mRadiusScale;
	openvdb::Real           mVelocityScale;
	std::vector<MyParticle> mParticleList;
public:

	typedef openvdb::Vec3R  PosType;

	MyParticleList(openvdb::Real rScale=1, openvdb::Real vScale=1)
		: mRadiusScale(rScale), mVelocityScale(vScale) {}
	void add(const openvdb::Vec3R &p, const openvdb::Real &r,
		const openvdb::Vec3R &v=openvdb::Vec3R(0,0,0))
	{
		MyParticle pa;
		pa.p = p;
		pa.r = r;
		pa.v = v;
		mParticleList.push_back(pa);
	}
	/// @return coordinate bbox in the space of the specified transfrom
	openvdb::CoordBBox getBBox(const openvdb::GridBase& grid) {
		openvdb::CoordBBox bbox;
		openvdb::Coord &min= bbox.min(), &max = bbox.max();
		openvdb::Vec3R pos;
		openvdb::Real rad, invDx = 1/grid.voxelSize()[0];
		for (size_t n=0, e=this->size(); n<e; ++n) {
			this->getPosRad(n, pos, rad);
			const openvdb::Vec3d xyz = grid.worldToIndex(pos);
			const openvdb::Real   r  = rad * invDx;
			for (int i=0; i<3; ++i) {
				min[i] = openvdb::math::Min(min[i], openvdb::math::Floor(xyz[i] - r));
				max[i] = openvdb::math::Max(max[i], openvdb::math::Ceil( xyz[i] + r));
			}
		}
		return bbox;
	}
	//typedef int AttributeType;
	// The methods below are only required for the unit-tests
	openvdb::Vec3R pos(int n)   const {return mParticleList[n].p;}
	openvdb::Vec3R vel(int n)   const {return mVelocityScale*mParticleList[n].v;}
	openvdb::Real radius(int n) const {return mRadiusScale*mParticleList[n].r;}

	//////////////////////////////////////////////////////////////////////////////
	/// The methods below are the only ones required by tools::ParticleToLevelSet
	/// @note We return by value since the radius and velocities are modified
	/// by the scaling factors! Also these methods are all assumed to
	/// be thread-safe.

	/// Return the total number of particles in list.
	///  Always required!
	size_t size() const { return mParticleList.size(); }

	/// Get the world space position of n'th particle.
	/// Required by ParticledToLevelSet::rasterizeSphere(*this,radius).
	void getPos(size_t n,  openvdb::Vec3R&pos) const { pos = mParticleList[n].p; }


	void getPosRad(size_t n,  openvdb::Vec3R& pos, openvdb::Real& rad) const {
		pos = mParticleList[n].p;
		rad = mRadiusScale*mParticleList[n].r;
	}
	void getPosRadVel(size_t n,  openvdb::Vec3R& pos, openvdb::Real& rad, openvdb::Vec3R& vel) const {
		pos = mParticleList[n].p;
		rad = mRadiusScale*mParticleList[n].r;
		vel = mVelocityScale*mParticleList[n].v;
	}
	// The method below is only required for attribute transfer
	void getAtt(size_t n, openvdb::Index32& att) const { att = openvdb::Index32(n); }
};

MStatus MpmSimulator::computeVDB(openvdb::FloatGrid::Ptr& ls, float voxelSize, float halfWidth, float volumeFactor)
{
	MStatus s;	
	int ithFrame = getCurFrame();

	MpmStatus result;
	if (!m_core.getRecorder().getStatus(ithFrame, result))
		return MS::kFailure;

	MPlug velocityFtrPlug = Global::getPlug(this, s_vdbVelocityFactorName[0]);
	MPlug vdbTypePlug = Global::getPlug(this, s_vdbTypeName[0]);
	short type = vdbTypePlug.asShort();

	const deque<Particle>& ptclList = result.getParticle();
	MyParticleList pa(volumeFactor, velocityFtrPlug.asFloat());
	const float factor = 3.f / (4.f * 3.14159265);
	for (int i = 0; i < ptclList.size(); ++i)
	{
		const Particle& ptcl = ptclList[i];
		const Vector3f& pos = ptcl.position;
		const Vector3f& vel = ptcl.velocity;
		float radius = pow(ptcl.volume * factor, 1.f/3.f);
		openvdb::Vec3R velocity(0,0,0);
		if (type == RASTERIZE_TRAIL)
		{
			velocity = openvdb::Vec3R(vel[0],vel[1],vel[2]);
		}
		pa.add(openvdb::Vec3R(pos[0], pos[1], pos[2]), radius, velocity);
	}

	ls = openvdb::createLevelSet<openvdb::FloatGrid>(voxelSize, halfWidth);
	ls->setName("outVDB");
	openvdb::tools::ParticlesToLevelSet<openvdb::FloatGrid> raster(*ls);

	MPlug rminPlug = Global::getPlug(this, s_vdbRminName[0]);
	MPlug rmaxPlug = Global::getPlug(this, s_vdbRmaxName[0]);
	raster.setRmin(min(rminPlug.asFloat(), rmaxPlug.asFloat()));
	raster.setRmax(max(rminPlug.asFloat(), rmaxPlug.asFloat()));
	raster.setGrainSize(1);//a value of zero disables threading
	if (type == RASTERIZE_SPHERE)
	{
		raster.rasterizeSpheres(pa);
	}
	else
	{
		MPlug sampleDistPlug = Global::getPlug(this, s_vdbVelocitySampleDistanceName[0]);
		raster.rasterizeTrails(pa, sampleDistPlug.asFloat());
	}
	raster.finalize();

	return s;
}

MStatus MpmSimulator::compute( const MPlug& plug, MDataBlock& data )
{
	MStatus s;
	if (plug == s_outputParticle)
	{
		MPlug inputPlug = Global::getPlug(this, s_inputParticleName[0]);
		MPlug outputPlug= Global::getPlug(this, s_outputParticleName[0]);
		MPlug samplePlug= Global::getPlug(this, s_sampleRateName[0]);

		if (inputPlug.isConnected() && outputPlug.isConnected())
		{
			MObject inputObj = inputPlug.asMObject();
			CHECK_MSTATUS_AND_RETURN_IT(s);

			MFnNObjectData inputFn(inputObj, &s);
			CHECK_MSTATUS_AND_RETURN_IT(s);

			MnParticle* inputPtr = inputFn.getParticleObjectPtr(&s);
			CHECK_MSTATUS_AND_RETURN_IT(s);
			if (!inputPtr)
				goto COMPUTE_END;

			int count = getNumSampledParticle();
			if (count <= 0)
				goto COMPUTE_END;
			inputPtr->setTopology(count);

			MFloatPointArray positionList, velocityList;
			s=inputPtr->getPositions(positionList);
			CHECK_MSTATUS_AND_RETURN_IT(s);
			s=inputPtr->getVelocities(velocityList);
			CHECK_MSTATUS_AND_RETURN_IT(s);

			MpmStatus status;
			bool res = m_core.getRecorder().getStatus(getCurFrame(), status);
			int sampleRate = samplePlug.asInt();
			PRINT_F("sampleRate %d, count %d", sampleRate, count);
			for (int ithPos = 0, ithSample = 0; ithPos < count; ithPos++, ithSample += sampleRate)
			{
				Vector3f newPos, newVel;
				status.getParticlePos(ithSample, newPos);
				status.getParticleVelocity(ithSample, newVel);
				positionList[ithPos] = MFloatPoint(newPos[0],newPos[1],newPos[2],1.f);
				velocityList[ithPos] = MFloatPoint(newVel[0],newVel[1],newVel[2],1.f);
			}
			s=inputPtr->setPositions(positionList);
			CHECK_MSTATUS_AND_RETURN_IT(s);
			s=inputPtr->setVelocities(velocityList);
			CHECK_MSTATUS_AND_RETURN_IT(s);

			outputPlug.setMObject(inputObj);
		}
	}
	else if (plug == s_numSampledParticle)
	{
		int frame = getCurFrame();
		MPlug numPtclPlug = Global::getPlug(this, s_numSampledParticleName[0]);
		numPtclPlug.setInt(getNumSampledParticle());
	}
	else if (plug == s_outputVDB)
	{
		MPlug imupdatePlug = Global::getPlug(this, s_immediateUpdateName[0]);
		if (imupdatePlug.asBool())
		{
			MPlug voxelSizePlug = Global::getPlug(this, s_vdbVoxelSizeName[0]);
			MPlug halfWidthPlug = Global::getPlug(this, s_vdbHalfWidthName[0]);
			MPlug volumeFactorPlug= Global::getPlug(this, s_vdbVolumeFactorName[0]);
			openvdb::FloatGrid::Ptr ls;
			s = computeVDB(ls, voxelSizePlug.asFloat(), halfWidthPlug.asFloat(), volumeFactorPlug.asFloat());
			CHECK_MSTATUS_AND_RETURN_IT(s);

			MPlug outputVDBPlug = Global::getPlug(this, s_outputVDBName[0]);
			MFnPluginData valFn;
			MObject valObj = valFn.create(OpenVDBData::id, &s);
			CHECK_MSTATUS_AND_RETURN_IT(s);

			OpenVDBData* data = (OpenVDBData*)valFn.data(&s);
			CHECK_MSTATUS_AND_RETURN_IT(s);
			if (!data)
				goto COMPUTE_END;

			data->insert(ls);
			outputVDBPlug.setMObject(valObj);
		}
	}

COMPUTE_END:
	data.setClean(plug);
	return s;
}

void* MpmSimulator::creator()
{
	return new MpmSimulator;
}

MStatus MpmSimulator::initialize()
{
	MStatus s;
	MFnNumericAttribute nAttr;
	MFnMatrixAttribute  mAttr;
	MFnTypedAttribute   tAttr;
	MFnEnumAttribute	eAttr;
	MFnUnitAttribute	uAttr;
	MFnCompoundAttribute cAttr;

	// solver param
	{
		s_time = uAttr.create(s_timeName[0], s_timeName[1], MFnUnitAttribute::kTime,1, &s);
		uAttr.setKeyable(true);
		uAttr.setStorable(false);
		uAttr.setHidden(false);
		uAttr.setWritable(true);
		uAttr.setReadable(false);
		uAttr.setAffectsAppearance(true);
		s = addAttribute(s_time);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_boxMin = nAttr.create(s_boxMinName[0], s_boxMinName[1], MFnNumericData::k3Float, -2, &s);
		nAttr.setStorable(true);
		nAttr.setWritable(true);
		s = addAttribute(s_boxMin);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_boxMax = nAttr.create(s_boxMaxName[0], s_boxMaxName[1], MFnNumericData::k3Float, 2, &s);
		nAttr.setStorable(true);
		nAttr.setWritable(true);
		s = addAttribute(s_boxMax);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_cellSize = nAttr.create(s_cellSizeName[0], s_cellSizeName[1], MFnNumericData::k3Float, 0.25, &s);
		nAttr.setStorable(true);
		nAttr.setWritable(true);
		nAttr.setMin(0.01);
		s = addAttribute(s_cellSize);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_nParticlePerCell = nAttr.create(s_nParticlePerCellName[0], s_nParticlePerCellName[1], MFnNumericData::kShort, 8, &s);
		nAttr.setStorable(true);
		nAttr.setWritable(true);
		nAttr.setMin(1);
		nAttr.setMax(200);
		s = addAttribute(s_nParticlePerCell);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_boundary = nAttr.create(s_boundaryName[0], s_boundaryName[1], MFnNumericData::kShort, 2, &s);
		nAttr.setStorable(true);
		nAttr.setWritable(true);
		nAttr.setMin(0);
		nAttr.setMax(10);
		s = addAttribute(s_boundary);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	// physical param
	{
		s_particleDensity = nAttr.create(s_particleDensityName[0], s_particleDensityName[1], MFnNumericData::kFloat, 400, &s);
		nAttr.setMin(1e-5);
		nAttr.setMax(1e12);
		nAttr.setSoftMin(10);
		nAttr.setSoftMax(10000);
		s = addAttribute(s_particleDensity);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_youngs = nAttr.create(s_youngsName[0], s_youngsName[1], MFnNumericData::kFloat, 1.4e5, &s);
		nAttr.setMin(1e-5);
		nAttr.setMax(1e12);
		nAttr.setSoftMin(1e4);
		nAttr.setSoftMax(10e4);
		s = addAttribute(s_youngs);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_poisson = nAttr.create(s_poissonName[0], s_poissonName[1], MFnNumericData::kFloat, 0.2, &s);
		nAttr.setMin(1e-3);
		nAttr.setMax(1e2);
		nAttr.setSoftMin(0.05);
		nAttr.setSoftMax(0.5);
		s = addAttribute(s_poisson);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_hardening = nAttr.create(s_hardeningName[0], s_hardeningName[1], MFnNumericData::kFloat, 10.f, &s);
		nAttr.setMin(0);
		nAttr.setMax(1e4);
		nAttr.setSoftMin(3);
		nAttr.setSoftMax(30);
		s = addAttribute(s_hardening);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_criticalCompression = nAttr.create(s_criticalCompressionName[0], s_criticalCompressionName[1], MFnNumericData::kFloat, 2.5e-2, &s);
		nAttr.setMin(0);
		nAttr.setMax(10);
		nAttr.setSoftMin(0.001);
		nAttr.setSoftMax(0.1);
		s = addAttribute(s_criticalCompression);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_criticalStretch = nAttr.create(s_criticalStretchName[0], s_criticalStretchName[1], MFnNumericData::kFloat, 7.5e-3, &s);
		nAttr.setMin(0);
		nAttr.setMax(10);
		nAttr.setSoftMin(0.001);
		nAttr.setSoftMax(0.01);
		s = addAttribute(s_criticalStretch);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_friction = nAttr.create(s_frictionName[0], s_frictionName[1], MFnNumericData::kFloat, 1.f, &s);
		nAttr.setMin(0);
		nAttr.setMax(1e5);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(5.0);
		s = addAttribute(s_friction);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_flip = nAttr.create(s_flipName[0], s_flipName[1], MFnNumericData::kFloat, 0.95, &s);
		nAttr.setMin(0);
		nAttr.setMax(10);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(1.5);
		s = addAttribute(s_flip);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_gravity = nAttr.create(s_gravityName[0], s_gravityName[1], MFnNumericData::k3Float, 0, &s);
		nAttr.setMin(-1e6);
		nAttr.setMax(1e6);
		s = addAttribute(s_gravity);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_deltaT = nAttr.create(s_deltaTName[0], s_deltaTName[1], MFnNumericData::kFloat, 1.0/24.f, &s);
		nAttr.setMin(1e-3);
		nAttr.setMax(10);
		nAttr.setSoftMin(0.01);
		nAttr.setSoftMax(0.1);
		s = addAttribute(s_deltaT);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_nSubStep = nAttr.create(s_nSubStepName[0], s_nSubStepName[1], MFnNumericData::kInt, 5, &s);
		nAttr.setMin(1);
		nAttr.setMax(1e4);
		nAttr.setSoftMin(1);
		nAttr.setSoftMax(15);
		s = addAttribute(s_nSubStep);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	// init param
	{
		s_initParticle = tAttr.create(s_initParticleName[0], s_initParticleName[1], MFnData::kPlugin, &s);
		tAttr.setReadable(false);
		tAttr.setArray(true);
		tAttr.setUsesArrayDataBuilder(true);
		tAttr.setAffectsAppearance(true);
		s = addAttribute(s_initParticle);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_initType = eAttr.create(s_initTypeName[0], s_initTypeName[1]);
		eAttr.addField("Init from OpenVDB",  INIT_FROM_VDB);
		eAttr.addField("Init a Sphere", INIT_SPHERE);
		eAttr.addField("Init two Spheres", INIT_TWO_SPHERES);
		eAttr.addField("Init Empty", INIT_EMPTY);
		eAttr.setDefault(INIT_EMPTY);
		eAttr.setHidden(false);
		eAttr.setReadable(true);
		eAttr.setWritable(true);
		eAttr.setStorable(true);
		s= addAttribute(s_initType);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_initTrans0 = mAttr.create(s_initTrans0Name[0], s_initTrans0Name[1]);
		mAttr.setHidden(false);
		mAttr.setReadable(true);
		mAttr.setWritable(true);
		mAttr.setKeyable(true);
		mAttr.setArray(true);
		mAttr.setStorable(true);
		mAttr.setUsesArrayDataBuilder(true);
		s = addAttribute(s_initTrans0);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_initTrans1 = mAttr.create(s_initTrans1Name[0], s_initTrans1Name[1]);
		mAttr.setHidden(false);
		mAttr.setReadable(true);
		mAttr.setWritable(true);
		mAttr.setKeyable(true);
		mAttr.setArray(true);
		mAttr.setStorable(true);
		mAttr.setUsesArrayDataBuilder(true);
		s = addAttribute(s_initTrans1);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_initDeltaTime = nAttr.create(s_initDeltaTimeName[0], s_initDeltaTimeName[1], MFnNumericData::kFloat, 1.f/24.f, &s);
		nAttr.setMin(1e-3);
		nAttr.setMax(10);
		nAttr.setSoftMin(0.01);
		nAttr.setSoftMax(0.1);
		s = addAttribute(s_initDeltaTime);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	// particle baking
	{
		s_numSampledParticle = nAttr.create(s_numSampledParticleName[0], s_numSampledParticleName[1], MFnNumericData::kInt, 20, &s);
		nAttr.setHidden(false);
		nAttr.setWritable(false);
		nAttr.setKeyable(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_numSampledParticle);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_particleStr = tAttr.create(s_particleStrName[0], s_particleStrName[1], MFnData::kString, &s);
		tAttr.setHidden(false);
		tAttr.setStorable(true);
		s = addAttribute(s_particleStr);

		s_inputParticle = tAttr.create(s_inputParticleName[0], s_inputParticleName[1], MFnData::kNObject, &s);
		tAttr.setReadable(false);
		tAttr.setHidden(false);
		tAttr.setAffectsAppearance(true);
		s = addAttribute(s_inputParticle);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_outputParticle= tAttr.create(s_outputParticleName[0], s_outputParticleName[1], MFnData::kNObject, &s);
		tAttr.setWritable(false);
		tAttr.setHidden(false);
		tAttr.setAffectsAppearance(true);
		s = addAttribute(s_outputParticle);
		attributeAffects(s_time, s_outputParticle);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_sampleRate = nAttr.create(s_sampleRateName[0], s_sampleRateName[1], MFnNumericData::kInt, 20, &s);
		nAttr.setMin(1);
		nAttr.setMax(1000000);
		nAttr.setSoftMin(1);
		nAttr.setSoftMax(100);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_sampleRate);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_outputVDB = tAttr.create(s_outputVDBName[0], s_outputVDBName[1], MFnData::kPlugin, &s);
		tAttr.setWritable(false);
		tAttr.setAffectsAppearance(true);
		s = addAttribute(s_outputVDB);
		attributeAffects(s_time, s_outputVDB);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_vdbVoxelSize = nAttr.create(s_vdbVoxelSizeName[0], s_vdbVoxelSizeName[1], MFnNumericData::kFloat, 0.3, &s);
		nAttr.setMin(0.001);
		nAttr.setMax(1000000);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(0.6);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbVoxelSize);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_vdbHalfWidth = nAttr.create(s_vdbHalfWidthName[0], s_vdbHalfWidthName[1], MFnNumericData::kFloat, 1.0, &s);
		nAttr.setMin(0.05);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(10);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbHalfWidth);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_vdbVolumeFactor = nAttr.create(s_vdbVolumeFactorName[0], s_vdbVolumeFactorName[1], MFnNumericData::kFloat, 5.0, &s);
		nAttr.setMin(0.05);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(10);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbVolumeFactor);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_vdbVelocityFactor = nAttr.create(s_vdbVelocityFactorName[0], s_vdbVelocityFactorName[1], MFnNumericData::kFloat, 1.0, &s);
		nAttr.setMin(-100);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.0);
		nAttr.setSoftMax(10);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbVelocityFactor);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_vdbVelocitySampleDistance = nAttr.create(s_vdbVelocitySampleDistanceName[0], s_vdbVelocitySampleDistanceName[1], MFnNumericData::kFloat, 1.0, &s);
		nAttr.setMin(0.05);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(10);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbVelocitySampleDistance);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_vdbType = eAttr.create(s_vdbTypeName[0], s_vdbTypeName[1]);
		eAttr.addField("Sphere",  RASTERIZE_SPHERE);
		eAttr.addField("Trail", RASTERIZE_TRAIL);
		eAttr.setHidden(false);
		eAttr.setReadable(true);
		eAttr.setWritable(true);
		eAttr.setStorable(true);
		s= addAttribute(s_vdbType);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_vdbRmin = nAttr.create(s_vdbRminName[0], s_vdbRminName[1], MFnNumericData::kFloat, 0.1, &s);
		nAttr.setMin(0.01);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(1);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbRmin);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_vdbRmax = nAttr.create(s_vdbRmaxName[0], s_vdbRmaxName[1], MFnNumericData::kFloat, 1.0, &s);
		nAttr.setMin(0.01);
		nAttr.setMax(100);
		nAttr.setSoftMin(0.1);
		nAttr.setSoftMax(1);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_vdbRmax);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_immediateUpdate = nAttr.create(s_immediateUpdateName[0], s_immediateUpdateName[1], MFnNumericData::kBoolean, false, &s);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_immediateUpdate);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		attributeAffects(s_inputParticle, s_outputParticle);
		attributeAffects(s_sampleRate, s_outputParticle);
		attributeAffects(s_sampleRate, s_numSampledParticle);
		attributeAffects(s_vdbVoxelSize, s_outputVDB);
		attributeAffects(s_vdbHalfWidth, s_outputVDB);
		attributeAffects(s_vdbVolumeFactor, s_outputVDB);
		attributeAffects(s_vdbVelocitySampleDistance, s_outputVDB);
		attributeAffects(s_vdbVelocityFactor, s_outputVDB);
		attributeAffects(s_vdbType, s_outputVDB);
		attributeAffects(s_immediateUpdate, s_outputVDB);
		attributeAffects(s_vdbRmin, s_outputVDB);
		attributeAffects(s_vdbRmax, s_outputVDB);
	}
	// loading and saving
	{
		s_saveEveryFrame = nAttr.create(s_saveEveryFrameName[0], s_saveEveryFrameName[1], MFnNumericData::kBoolean, false, &s);
		nAttr.setHidden(false);
		s = addAttribute(s_saveEveryFrame);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_saveFilePath = tAttr.create(s_saveFilePathName[0], s_saveFilePathName[1], MFnData::kString);
		tAttr.setKeyable(true);
		tAttr.setStorable(true);
		tAttr.setHidden(false);
		tAttr.setWritable(true);
		s = addAttribute(s_saveFilePath);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_saveFilePrefix = tAttr.create(s_saveFilePrefixName[0], s_saveFilePrefixName[1], MFnData::kString);
		tAttr.setKeyable(true);
		tAttr.setStorable(true);
		tAttr.setHidden(false);
		tAttr.setWritable(true);
		s = addAttribute(s_saveFilePrefix);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	// collider
	{
		s_colliderVdb = tAttr.create(s_colliderVdbName[0], s_colliderVdbName[1], MFnData::kPlugin, &s);
		tAttr.setReadable(false);
		tAttr.setCached(false);
		tAttr.setArray(true);
		tAttr.setUsesArrayDataBuilder(true);
		tAttr.setAffectsAppearance(true);
		s = addAttribute(s_colliderVdb);
		CHECK_MSTATUS_AND_RETURN_IT(s);


		s_colliderTrans = mAttr.create(s_colliderTransName[0], s_colliderTransName[1]);
		mAttr.setHidden(false);
		mAttr.setReadable(true);
		mAttr.setWritable(true);
		mAttr.setKeyable(true);
		mAttr.setCached(false);
		mAttr.setArray(true);
		mAttr.setStorable(true);
		mAttr.setUsesArrayDataBuilder(true);
		s = addAttribute(s_colliderTrans);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	// display
	{
		s_displayType = eAttr.create(s_displayTypeName[0], s_displayTypeName[1]);
		eAttr.addField("This Frame",  DISP_THIS_FRAME);
		eAttr.addField("Last Frame", DISP_LAST_FRAME);
		eAttr.setDefault(DISP_THIS_FRAME);
		eAttr.setHidden(false);
		eAttr.setReadable(true);
		eAttr.setWritable(true);
		eAttr.setStorable(true);
		eAttr.setAffectsAppearance(true);
		s= addAttribute(s_displayType);
		CHECK_MSTATUS_AND_RETURN_IT(s);
		
		s_displaySdf = nAttr.create(s_displaySdfName[0], s_displaySdfName[1], MFnNumericData::kBoolean, false, &s);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_displaySdf);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_displaySdfVel = nAttr.create(s_displaySdfVelName[0], s_displaySdfVelName[1], MFnNumericData::kBoolean, false, &s);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_displaySdfVel);
		CHECK_MSTATUS_AND_RETURN_IT(s);

		s_displayGrid= nAttr.create(s_displayGridName[0], s_displayGridName[1], MFnNumericData::kBoolean, true, &s);
		nAttr.setHidden(false);
		nAttr.setAffectsAppearance(true);
		s = addAttribute(s_displayGrid);
		CHECK_MSTATUS_AND_RETURN_IT(s);
	}
	return s;
}

bool MpmSimulator::initSolver()
{
	int frame = getCurFrame();
	MPlug boxMinPlug = Global::getPlug(this, s_boxMinName[0]);
	MPlug boxMaxPlug = Global::getPlug(this, s_boxMaxName[0]);
	MPlug cellSizePlug = Global::getPlug(this, s_cellSizeName[0]);
	MPlug nParticlePlug = Global::getPlug(this, s_nParticlePerCellName[0]);
	MPlug boundaryPlug = Global::getPlug(this, s_boundaryName[0]);

	MPlug youngsPlug = Global::getPlug(this, s_youngsName[0]);
	MPlug possionPlug = Global::getPlug(this, s_poissonName[0]);
	MPlug hardenPlug = Global::getPlug(this, s_hardeningName[0]);
	MPlug cCompPlug = Global::getPlug(this, s_criticalCompressionName[0]);
	MPlug cStrePlug = Global::getPlug(this, s_criticalStretchName[0]);
	MPlug frictionPlug = Global::getPlug(this, s_frictionName[0]);
	MPlug flipPlug = Global::getPlug(this, s_flipName[0]);
	MPlug gravityPlug = Global::getPlug(this, s_gravityName[0]);
	MPlug deltaTPlug = Global::getPlug(this, s_deltaTName[0]);
	MPlug particleDensityPlug = Global::getPlug(this, s_particleDensityName[0]);
	MPlug nSubstepPlug = Global::getPlug(this, s_nSubStepName[0]);

	MPlug initTypePlug = Global::getPlug(this, s_initTypeName[0]);

	MStatus s;
	Vector3f gridMin, gridMax, cellSize;
	s = Global::getFloat(boxMinPlug, &gridMin[0], 3);
	CHECK_MSTATUS_AND_RETURN(s, false);
	s = Global::getFloat(boxMaxPlug, &gridMax[0], 3);
	CHECK_MSTATUS_AND_RETURN(s, false);
	s = Global::getFloat(cellSizePlug, &cellSize[0], 3);
	CHECK_MSTATUS_AND_RETURN(s, false);
	int nParticle = nParticlePlug.asInt();
	int boundary = boundaryPlug.asInt();
	
	if (!cellSize.norm())
		return false;
	bool res = m_core.initGrid(gridMin.cwiseMin(gridMax), gridMax.cwiseMax(gridMin), cellSize.cwiseAbs(), boundary, frame);

	Vector3f gravity;
	s = Global::getFloat(gravityPlug, &gravity[0], 3);
	CHECK_MSTATUS_AND_RETURN(s, false);
	float mayaDeltaT = deltaTPlug.asFloat();
	m_core.setConfigure(youngsPlug.asFloat(),
						possionPlug.asFloat(),
						hardenPlug.asFloat(),
						cCompPlug.asFloat(),
						cStrePlug.asFloat(),
						frictionPlug.asFloat(),
						flipPlug.asFloat(),
						mayaDeltaT / nSubstepPlug.asInt(),
						mayaDeltaT,
						particleDensityPlug.asFloat(),
						gravity);

	m_core.getRecorder().clear();
	if (initTypePlug.asShort() == INIT_SPHERE)
		m_core.addBall(Vector3f(0,0,0), 1, nParticle, frame);
	else if (initTypePlug.asShort() == INIT_TWO_SPHERES)
		m_core.addTwoBalls(nParticle, frame);
	else if (initTypePlug.asShort() == INIT_FROM_VDB)
		res &= initParticle(frame);
	else if (initTypePlug.asShort() == INIT_EMPTY)
	{
		res &= true;
	}
	updateCollider(frame);
	m_core.commitInit(frame);

	if (res)
	{
		MGlobal::displayInfo("init succeed!");
	}
	else
	{
		MGlobal::displayInfo("init fail!");
	}
	return res;
}

bool MpmSimulator::updateCollider(int ithFrame)
{
	MStatus s;
	MPlug colliderVdbPlug = Global::getPlug(this, s_colliderVdbName[0]);
	MPlug colliderTransPlug= Global::getPlug(this, s_colliderTransName[0]);
		
	m_core.resetSdf();
	for (unsigned i = 0; i < colliderVdbPlug.numElements(&s); i++)
	{
		MPlug ithElementPlug = colliderVdbPlug.elementByPhysicalIndex(i, &s);
		if (!s || !ithElementPlug.isConnected())
			continue;

		int logicalIdx     = ithElementPlug.logicalIndex(&s);
		MPlug ithTransPlug= colliderTransPlug.elementByLogicalIndex(logicalIdx);

		MObject transObj = ithTransPlug.asMObject();
		MFnMatrixData transData(transObj, &s);
		if (!s)
			continue;

		MMatrix transM = transData.matrix().transpose();
		Eigen::Matrix4f transE;
		transE <<	transM(0,0), transM(0,1), transM(0,2), transM(0,3), 
					transM(1,0), transM(1,1), transM(1,2), transM(1,3), 
					transM(2,0), transM(2,1), transM(2,2), transM(2,3),
					transM(3,0), transM(3,1), transM(3,2), transM(3,3);

		MObject valObj;
		s = ithElementPlug.getValue(valObj);
		if (!s)
			continue;

		OpenVDBData* data;
		s = Global::getVDBData(valObj, data);
		
		if (!s || !data)
			continue;

		std::vector<openvdb::GridBase::ConstPtr> grids;
		mvdb::getGrids(grids, *data, "");
		for (int ithGrid = 0; ithGrid < grids.size(); ++ithGrid)
		{
			openvdb::GridBase::ConstPtr pGridBase = grids[ithGrid];
			if (!pGridBase)
				continue;
			else if (pGridBase->isType<openvdb::FloatGrid>())
				m_core.addSdf<openvdb::FloatGrid>(pGridBase, transE, logicalIdx, ithFrame);
			else if (pGridBase->isType<openvdb::DoubleGrid>())
				m_core.addSdf<openvdb::DoubleGrid>(pGridBase, transE, logicalIdx, ithFrame);
		}
	}
	return false;
}

bool MpmSimulator::initParticle(int ithFrame)
{
	MPlug initParticlePlug = Global::getPlug(this, s_initParticleName[0]);
	MPlug nParticlePlug = Global::getPlug(this, s_nParticlePerCellName[0]);
	MPlug initTrans0Plug = Global::getPlug(this, s_initTrans0Name[0]);
	MPlug initTrans1Plug = Global::getPlug(this, s_initTrans1Name[0]);
	MPlug initDeltaTPlug = Global::getPlug(this, s_initDeltaTimeName[0]);
	MStatus s;

	int nPPC = nParticlePlug.asInt();
	float deltaT = initDeltaTPlug.asFloat();

	for (unsigned i = 0; i < initParticlePlug.numElements(&s); i++)
	{
		MPlug ithElementPlug = initParticlePlug.elementByPhysicalIndex(i, &s);
		if (!s || !ithElementPlug.isConnected())
			continue;

		int logicalIdx     = ithElementPlug.logicalIndex(&s);
		MPlug ithTrans0Plug= initTrans0Plug.elementByLogicalIndex(logicalIdx);
		MPlug ithTrans1Plug= initTrans1Plug.elementByLogicalIndex(logicalIdx);
		MObject trans0Obj = ithTrans0Plug.asMObject();
		MObject trans1Obj = ithTrans1Plug.asMObject();
		MFnMatrixData trans0Data(trans0Obj, &s), trans1Data(trans1Obj, &s);
		if (!s)
			continue;
		MMatrix trans0 = trans0Data.matrix();
		MMatrix trans1 = trans1Data.matrix();	
		Eigen::Matrix4f velMatE;
		if (abs(trans0.det4x4()) > 0.01)
		{
			MMatrix velMat = (trans1 - trans0) * trans0.inverse() * (1.0/deltaT);
			Eigen::Matrix4d velMatEd;
			velMatEd <<	velMat(0,0), velMat(0,1), velMat(0,2), velMat(0,3), 
						velMat(1,0), velMat(1,1), velMat(1,2), velMat(1,3), 
						velMat(2,0), velMat(2,1), velMat(2,2), velMat(2,3),
						velMat(3,0), velMat(3,1), velMat(3,2), velMat(3,3);
			velMatE = velMatEd.cast<float>();
			/*
			PRINT_F("vel:\n\t%lf\t%lf\t%lf\t%lf\n\t%lf\t%lf\t%lf\t%lf\n\t%lf\t%lf\t%lf\t%lf\n\t%lf\t%lf\t%lf\t%lf",
				velMat(0,0), velMat(0,1), velMat(0,2), velMat(0,3), 
				velMat(1,0), velMat(1,1), velMat(1,2), velMat(1,3), 
				velMat(2,0), velMat(2,1), velMat(2,2), velMat(2,3),
				velMat(3,0), velMat(3,1), velMat(3,2), velMat(3,3));*/
		}
		else
			velMatE.setZero();

		MObject valObj;
		s = ithElementPlug.getValue(valObj);
		if (!s)
			continue;

		OpenVDBData* data;
		s = Global::getVDBData(valObj, data);
		
		if (!s || !data)
			continue;

		std::vector<openvdb::GridBase::ConstPtr> grids;
		mvdb::getGrids(grids, *data, "");
		for (int ithGrid = 0; ithGrid < grids.size(); ++ithGrid)
		{
			openvdb::GridBase::ConstPtr pGridBase = grids[ithGrid];
			if (!pGridBase)
				continue;
			else if (pGridBase->isType<openvdb::FloatGrid>())
				m_core.addParticleGrid<openvdb::FloatGrid>(pGridBase, velMatE, nPPC, ithFrame);
			else if (pGridBase->isType<openvdb::DoubleGrid>())
				m_core.addParticleGrid<openvdb::DoubleGrid>(pGridBase, velMatE, nPPC, ithFrame);
		}
	}
	return true;
}


bool MpmSimulator::stepSolver()
{
	MPlug deltaTPlug = Global::getPlug(this, s_deltaTName[0]);
	MPlug nSubstepPlug = Global::getPlug(this, s_nSubStepName[0]);
	int frame = getCurFrame();
	updateCollider(frame);
	return m_core.step(frame, deltaTPlug.asFloat(), nSubstepPlug.asInt());
}

bool MpmSimulator::loadCurStatus(const char* fileName, bool isAppend)
{
	PRINT_F("load status from file: %s", fileName);
	int curFrame = getCurFrame();
	bool res = m_core.getRecorder().readStatus(fileName, curFrame,	isAppend);
	return res;
}

bool MpmSimulator::saveCurStatus(const char* customName)
{
	int curFrame = getCurFrame();
	char curFrameStr[30];
	sprintf(curFrameStr, "%05d.dat", curFrame);

	MPlug pathPlug = Global::getPlug(this, s_saveFilePathName[0]);
	MPlug prefixPlug= Global::getPlug(this, s_saveFilePrefixName[0]);
	MString path = pathPlug.asString();
	MString prefix= prefixPlug.asString();
	MString fullPath;
	if (path.length())
	{
		fullPath += path + "\\";
	}
	fullPath += prefix + curFrameStr;

	PRINT_F("save particles to %s", fullPath.asChar());
	const char* fileName = customName ? customName : fullPath.asChar();
	bool res = m_core.getRecorder().writeStatus(fileName, curFrame);
	return res;
}

















