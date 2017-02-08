// use for updates e..g use walls so you dont have to use the 
//width/height shit so it doesn't get complicated, also can use the collisions to check each others within their updates.

//#//include "wall.h"
//#include "block.h"
//#include "collisions.h"
//#include "isIntersecting.h"
//#include "ball.h"

/*
void testCollision1(Paddle& mPaddle, Ball& mBall)
{
	if(!isIntersecting(mPaddle, mBall)) return;

	mBall.vBallVelocity.y = -mBall.ballVelocity;
	if(mBall.cBall.getPosition().x < mPaddle.rPaddle.getPosition().x) mBall.vBallVelocity.x = -mBall.ballVelocity;
	else mBall.vBallVelocity.x = mBall.ballVelocity;
}

/*void testCollision2(Block& mBlock, Ball& mBall)
{
	if(!isIntersecting(mBlock, mBall)) return;
	mBlock.bDestroyed = true;

	float overlapLeft = mBall.fGetRight() - mBlock.fGetLeft();
	float overlapRight = mBlock.fGetRight() - mBall.fGetLeft();
	float overlapTop = mBall.fGetBottom() - mBlock.fGetTop();
	float overlapBottom = mBlock.fGetBottom() - mBall.fGetTop();

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

	if(abs(minOverlapX) < abs(minOverlapY))
		mBall.vBallVelocity.x = ballFromLeft ? -mBall.ballVelocity : mBall.ballVelocity;
	else
		mBall.vBallVelocity.y = ballFromTop ? -mBall.ballVelocity : mBall.ballVelocity;	
}*/